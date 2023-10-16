#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int numerator=1, denominator=1;//분자, 분모

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		numerator *= n;
		n--;
		denominator *= (i + 1);
	}

	int result = numerator / denominator;

	cout << result << '\n';


	return 0;
}