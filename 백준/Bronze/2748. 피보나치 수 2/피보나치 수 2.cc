#include <iostream>
#include <vector>

using namespace std;

vector<long long int> dpTable;

long long int memoization(int n) {
	if (n == 0) {
		dpTable[n] = 0;
		return 0;
	}

	else if (n == 1) {
		dpTable[n] = 1;
		return 1;
	}

	else {
		if (dpTable[n - 1] < 0) {
			dpTable[n-1] = memoization(n - 1);
		}
		if (dpTable[n - 2] < 0) {
			dpTable[n - 2] = memoization(n - 2);
		}

		long long int result = dpTable[n - 1] + dpTable[n - 2];
		dpTable[n] = result;
		return result;
	}
}


int main(void) {
	int input;

	cin >> input;
	
	dpTable = vector<long long int>(91, -1);

	long long int result = memoization(input);

	cout << result << '\n';

	return 0;
}