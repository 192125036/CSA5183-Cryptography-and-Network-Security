#include <stdio.h>
#include<math.h>
int main()
{
	
}

#include <stdio.h>

int mod_inverse(int a, int m) {
    // Calculate modular inverse of 'a' under modulo 'm'
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // No modular inverse exists
}

char encrypt(char p, int a, int b) {
    if (p >= 'a' && p <= 'z') {
        return (char)((a * (p - 'a') + b) % 26 + 'a');
    } else if (p >= 'A' && p <= 'Z') {
        return (char)((a * (p - 'A') + b) % 26 + 'A');
    } else {
        return p; // Non-alphabetic characters remain unchanged
    }
}

int main() {
    int a, b;
    char plaintext[100];
    
    printf("Enter the value of a (must be coprime with 26): ");
    scanf("%d", &a);
    
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Invalid value of 'a'. It must be coprime with 26.\n");
        return 1;
    }
    
    printf("Enter the value of b: ");
    scanf("%d", &b);
    
    if (b < 0 || b >= 26) {
        printf("Invalid value of 'b'. It must be in the range [0 , 26).\n");
        return 1;
    }
    
    // Check if 'a' has a modular inverse under modulo 26
    int inverse = mod_inverse(a, 26);
    if (inverse == -1) {
        printf("Invalid value of 'a'. Modular inverse does not exist.\n");
        return 1;
    }

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", encrypt(plaintext[i], a, b));
    }
    printf("\n");

    return 0;
}
