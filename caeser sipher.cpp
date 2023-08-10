#include <stdio.h>
#include <string.h>

// Function to perform Caesar encryption
void encryptCaesar(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }

        message[i] = ch;
    }
}

// Function to perform Caesar decryption
void decryptCaesar(char *message, int key) {++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    encryptCaesar(message, 26 - key); // Decryption is just encryption with the inverse key
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    // Remove the newline character from the input
    if (strlen(message) > 0 && message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    encryptCaesar(message, key);
    printf("Encrypted message: %s\n", message);

    decryptCaesar(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
    
}

