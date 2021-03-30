#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int num;
	int numcopy;
	int result;
	int decom = 0;

	scanf("%d", &num);


	for (int i = 1; i < num; i++) {
		result = num - i;
		numcopy = i;
		while (numcopy != 0) {
			result -= (numcopy % 10);
			numcopy /= 10;
		}
		if (result == 0){
			decom = i;
			break;
		}
	}

	printf("%d", decom);

	return 0;
}
