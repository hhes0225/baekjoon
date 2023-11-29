#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double a, b, c;
	int tCase = 1;

	while (1) {
		cin >> a >> b >> c;
		//c가 가장 긴 변의 길이임

		if (a == 0.0 && b == 0.0 && c == 0.0)
			break;

		cout <<"Triangle #" << tCase++ <<"\n";

		

		if (a == -1) {
			if (a >= c || b >= c || b==0 || c==0) {
				printf("Impossible.\n\n");
				continue;
			}

			a = sqrt(pow(c, 2) - pow(b, 2));
			printf("a = %.3lf\n\n", a);
		}
		else if (b == -1) {
			if (a >= c || b >= c || a==0 || c==0) {
				printf("Impossible.\n\n");
				continue;
			}

			b = sqrt(pow(c, 2) - pow(a, 2));
			printf("b = %.3lf\n\n", b);
		}
		else {//c == -1
			if (a == 0 || b == 0) {
				printf("Impossible.\n\n");
				continue;
			}


			c = sqrt(pow(a, 2) + pow(b, 2));
			printf("c = %.3lf\n\n", c);
		}

	}

	return 0;
}