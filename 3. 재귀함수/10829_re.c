#include <stdio.h>
#pragma warning(disable:4996)

void dec2bin(unsigned long long int dec);
int main(void) {
	long long int decimal;

	scanf("%llu", &decimal);

	dec2bin(decimal);
	
	return 0;
}
void dec2bin(unsigned long long int dec) {
	if (dec != 1) {
		dec2bin(dec / 2);
	}

	printf("%d", dec%2);
}
