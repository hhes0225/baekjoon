#include <iostream>

using namespace std;

int main(void) {
	int tCase;
	int sum;
	int maxMoney=0;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		if (a == b && b == c) {
			sum = 10000 + a * 1000;
		}
		else if (a == b || b == c || a==c) {
			if (a == b || a == c) {
				sum = 1000 + a * 100;
			}
			else {
				sum = 1000 + b * 100;
			}

		}
		else {
			int tmpMax;

			tmpMax = max(a, b);
			tmpMax = max(tmpMax, c);

			sum = tmpMax * 100;
		}

		maxMoney = max(maxMoney, sum);
	}

	cout << maxMoney << endl;

	return 0;
}