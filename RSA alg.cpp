#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to perform modular exponentiation
int modExp(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    int p = 61; // Prime number 1
    int q = 53; // Prime number 2
    int n, phi, e, d;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e: a number that is coprime with phi and less than phi
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Find d: modular inverse of e mod phi
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            break;
    }

    int message = 88; // Message to be encrypted
    int encrypted_msg = modExp(message, e, n);
    int decrypted_msg = modExp(encrypted_msg, d, n);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_msg);
    printf("Decrypted message: %d\n", decrypted_msg);

    return 0;
}

