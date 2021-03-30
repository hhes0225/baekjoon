#include <stdio.h>
#pragma warning(disable:4996)
int Tn(int x);

int main(void) {
	int num;
	int n = 0;
	int count;
	bool tof = 0;

	scanf("%d", &count);

	for(int a = 0;a<count;a++){
		tof = 0;
		scanf("%d", &num);

		while (num >= Tn(n)) {
			n++;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				for (int k = 1; k < n; k++) {
					if (num - (Tn(i) + Tn(j) + Tn(k)) == 0) {
						printf("1\n");
						tof = 1;
						break;
					}
				}
				if (tof)
					break;
			}
			if (tof)
				break;
		}
		if(!tof)
			printf("0\n");
	}

	return 0;
}
int Tn(int x) {
	return (x * (x + 1)) / 2;
}
