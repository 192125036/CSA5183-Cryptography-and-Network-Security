#include <stdio.h>

void encrypt(int p[] , int k[][3], int c[]) {
	for (int i=0;i<3;i++) {
		c[i]=0;
		for(int j=0;j<3;j++) c[i] += k[i][j] * p[j];
		c[i]%=26;
	}
}

int main() {
	int k[][3]= {{6,24,1}, {13,16,10},{20,17,15}};
	int p[] = {0,1,2}, c[3];
	
	encrypt(p,k,c);
	
	printf("Plaintext: %d %d %d\n", p[0],p[1],p[2]);
	printf("Ciphertext: %d %d %d\n", c[0],c[1],c[2]);
	
	return 0;
}
