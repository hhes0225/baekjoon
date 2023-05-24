#include <iostream>
using namespace std;

int main(void) {
	long long int a, b, c;
	long long int result;
	int numbers[10] = { 0, };

	cin >> a >> b >> c;

	result = a * b * c;

	while (result>0) {
		numbers[result % 10]++;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << endl;;
	}

	return 0;
}