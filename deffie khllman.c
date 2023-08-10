#include <stdio.h>
#include <math.h>

// Function to compute (base^exponent) % modulus
int power(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main() {
    int modulus, base; // Publicly shared values
    int alicePrivate, bobPrivate; // Private keys for Alice and Bob
    int alicePublic, bobPublic; // Public keys for Alice and Bob
    int sharedSecretAlice, sharedSecretBob; // Shared secrets

    printf("Enter modulus and base: ");
    scanf("%d %d", &modulus, &base);

    printf("Enter Alice's private key: ");
    scanf("%d", &alicePrivate);

    printf("Enter Bob's private key: ");
    scanf("%d", &bobPrivate);

    // Compute public keys
    alicePublic = power(base, alicePrivate, modulus);
    bobPublic = power(base, bobPrivate, modulus);

    // Compute shared secrets
    sharedSecretAlice = power(bobPublic, alicePrivate, modulus);
    sharedSecretBob = power(alicePublic, bobPrivate, modulus);

    printf("Alice's public key: %d\n", alicePublic);
    printf("Bob's public key: %d\n", bobPublic);

    printf("Shared secret computed by Alice: %d\n", sharedSecretAlice);
    printf("Shared secret computed by Bob: %d\n", sharedSecretBob);

    return 0;
}
