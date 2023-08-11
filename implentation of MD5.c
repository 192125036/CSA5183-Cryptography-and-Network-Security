#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
} MD5_CTX;

void md5_init(MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const uint8_t *input, size_t input_len);
void md5_final(MD5_CTX *ctx, uint8_t result[16]);

int main() {
    MD5_CTX ctx;
    uint8_t input[100];
	printf("Enter the hash value: ");
	scanf("%s",input);
    uint8_t result[16];

    md5_init(&ctx);
    md5_update(&ctx, input, strlen((const char *)input));
    md5_final(&ctx, result);

    printf("MD5 Hash: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    return 0;
}

void md5_init(MD5_CTX *ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;

    ctx->count[0] = ctx->count[1] = 0;
}

void md5_update(MD5_CTX *ctx, const uint8_t *input, size_t input_len) {
    // Implementation of the update function
    // ...
}

void md5_final(MD5_CTX *ctx, uint8_t result[16]) {
	
    // Implementation of the finalization function
    // ...+
}
