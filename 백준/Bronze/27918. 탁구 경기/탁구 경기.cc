#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int tCase;
	string winner;

	int d = 0, p = 0;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> winner;

		if (winner == "D") {
			d++;
		}
		else {
			p++;
		}

		if (d >= p + 2 || p >= d + 2) {
			break;
		}
	}

	cout << d << ":" << p << endl;

	return 0;
}