#include <iostream>

using namespace std;

int main(void) {
	long long int n1, n2;
	long long int gcd;
	long long int lcm;
	long long int smaller;

	cin >> n1 >> n2;

	if (n1 > n2)
		smaller = n2;
	else
		smaller = n1;

	for (int i = 1; i <= smaller; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			gcd = i;
		}
	}

	lcm = gcd * (n1 / gcd) * (n2 / gcd);

	cout << lcm << '\n';

	return 0;
}