#include <iostream>

using namespace std;

int main(void) {
	int round;

	cin >> round;

	int a=0, b=0;

	for (int i = 0; i < round; i++) {
		int tmpa, tmpb;

		cin >> tmpa >> tmpb;

		if (tmpa > tmpb)
			a++;
		else if (tmpa < tmpb)
			b++;
	}

	cout << a << " " << b << '\n';
	return 0;
}