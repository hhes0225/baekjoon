#include <iostream>
#include <vector>

using namespace std;

vector<int> dpTable;
int zero=0;
int one = 0;

int memoization(int n) {
	if (n == 0) {
		zero++;
		dpTable[0] = 0;
		return 0;
	}
	else if (n == 1) {
		one++;
		dpTable[1] = 1;
		return 1;
	}
	else {
		if (dpTable[n - 1] < 0) {
			dpTable[n - 1] = memoization(n - 1);
		}
		if (dpTable[n - 2] < 0) {
			dpTable[n - 2] = memoization(n - 2);
		}

		int result = dpTable[n - 1] + dpTable[n - 2];
		dpTable[n] = result;
		return result;
	}
}

int main(void) {
	int tCase;
	int input;

	dpTable = vector<int>(41, -1);

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		int result = memoization(input);

		if(input>1){
			zero = dpTable[input - 1];
			one = dpTable[input];
		}

		cout << zero << " " << one << '\n';

		zero = 0;
		one = 0;
	}

	return 0;
}