#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int a, b, c, d, e, f;
	int x = 0, y = 0;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if ((a * i + b * j == c) && (d * i + e * j == f)) {
				x = i;
				y = j;
				break;
			}
		}
		if (x)
			break;
	}

	printf("%d %d", x, y);
	return 0;
}
