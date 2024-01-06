#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int sum=0;
	bool stop = false;

	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;

		if (abs(sum - 100) >= abs(sum + input - 100) && stop==false) {
			sum += input;
		}
		else
			stop = true;
	}

	cout << sum;
}