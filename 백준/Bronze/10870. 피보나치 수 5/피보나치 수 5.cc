#include <iostream>
#include <vector>
using namespace std;

/*
	boj 10870
	피보나치 수는 0과 1로 시작한다. 
	0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 
	그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

	이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

	n=17일때 까지 피보나치 수를 써보면 다음과 같다.

	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

	n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
*/

vector<int> dpTable;

int memoization(int n) {
	if (n == 0) {
		dpTable[n] = 0;
		return 0;
	}
	else if (n == 1) {
		dpTable[1] = 1;
		return 1;
	}
	else {
		if (dpTable[n - 1] == 0) {
			dpTable[n - 1] = memoization(n - 1);
		}
		else if (dpTable[n - 2] == 0) {
			dpTable[n - 2] = memoization(n - 2);
		}

		int result = dpTable[n - 1] + dpTable[n - 2];
		return result;

	}
}

int main(void) {
	int input;
	
	dpTable = vector<int>(21, 0);

	cin >> input;

	int result = memoization(input);

	cout << result;


	return 0;
}