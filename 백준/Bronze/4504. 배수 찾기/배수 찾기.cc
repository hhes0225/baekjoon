#include <iostream>

using namespace std;

int main(void) {
	int mod;
	int mul;
	int isMul;

	cin >> mod;
	

	while (1) {
		cin >> mul;

		if (mul == 0)
			break;

		isMul = mul % mod;

		if (isMul == 0) {
			cout << mul << " is a multiple of " << mod << "." << endl;
		}
		else {
			cout << mul << " is NOT a multiple of " << mod<<"." << endl;
		}
	}
}