#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to generate the key table
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int k = 0;
    int isPresent[26] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (k < strlen(key)) {
                if (!isPresent[key[k] - 'A']) {
                    keyTable[i][j] = key[k];
                    isPresent[key[k] - 'A'] = 1;
                    k++;
                } else {
                    j--;
                    k++;
                }
            } else {
                for (int l = 0; l < 26; l++) {
                    if (!isPresent[l]) {
                        keyTable[i][j] = l + 'A';
                        isPresent[l] = 1;
                        break;
                    }
                }
            }
        }
    }
}

// Function to search for the characters in the key table
void searchChar(char keyTable[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to perform Playfair encryption
void encrypt(char keyTable[SIZE][SIZE], char plaintext[], char ciphertext[]) {
    int i = 0;
    while (i < strlen(plaintext)) {
        char ch1 = plaintext[i];
        char ch2 = plaintext[i + 1];
        int row1, col1, row2, col2;
        searchChar(keyTable, ch1, &row1, &col1);
        searchChar(keyTable, ch2, &row2, &col2);

        if (row1 == row2) {
            ciphertext[i] = keyTable[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = keyTable[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = keyTable[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = keyTable[row1][col2];
            ciphertext[i + 1] = keyTable[row2][col1];
        }
        i += 2;
    }
}

int main() {
    char key[26];
    char keyTable[SIZE][SIZE];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the key: ");
    scanf("%s", key);

    generateKeyTable(key, keyTable);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Convert plaintext to uppercase
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = toupper(plaintext[i]);
    }

    encrypt(keyTable, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
