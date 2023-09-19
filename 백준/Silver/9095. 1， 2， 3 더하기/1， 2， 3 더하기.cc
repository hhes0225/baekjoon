#include <iostream>
#include <vector>
using namespace std;

/*
	boj 9095
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

	1+1+1+1
	1+1+2
	1+2+1
	2+1+1
	2+2
	1+3
	3+1
	정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

/*
	규칙: 1, 2 3의 합으로 나타내야 하므로
	n=5일때
	n = 1 + /4 -> 7가지
	n = 2 + /3 -> 4가지
	n = 3 + /2 -> 2가지
	4부터는 1,2,3의 합에 위배되기 때문에 포함 X
	앞은 경우의 수 안따지고 뒤만 경우의 수 따짐
	7+2+4 = 13
*/

vector<int> dpTable;

int memoization(int n) {
	if (n == 1) {
		dpTable[n] = 1;
		return 1;
	}
	else if (n == 2) {
		dpTable[n] = 2;
		return 2;
	}
	else if (n == 3) {
		dpTable[n] = 4;
		return 4;
	}
	else {
		if (dpTable[n-1] < 0) {
			dpTable[n-1] = memoization(n - 1);
		}
		if (dpTable[n - 2] < 0) {
			dpTable[n - 2] = memoization(n - 2);
		}
		if (dpTable[n - 3] < 0) {
			dpTable[n - 3] = memoization(n - 3);
		}

		dpTable[n] = dpTable[n - 1] + dpTable[n - 2] + dpTable[n - 3];
		return dpTable[n];
	}
}

int main(void) {
	int tCase;
	int input;

	cin >> tCase;

	dpTable = vector<int>(12, -1);

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		int result = memoization(input);
		cout << result << '\n';
	}

	return 0;
}