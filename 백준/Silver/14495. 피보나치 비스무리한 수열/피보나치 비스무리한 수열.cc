#include <iostream>
#include <vector>

using namespace std;

/*
	boj 14495
	피보나치 비스무리한 수열은 f(n) = f(n-1) + f(n-3)인 수열이다. 
	f(1) = f(2) = f(3) = 1이며 피보나치 비스무리한 수열을 나열하면 다음과 같다.

	1, 1, 1, 2, 3, 4, 6, 9, 13, 19, ...

	자연수 n을 입력받아 n번째 피보나치 비스무리한 수열을 구해보자!
*/

vector<long long int> dpTable;

long long int memoization(int n) {
	if (n <= 3) {
		dpTable[n] = 1;
		return 1;
	}
	else {
		if (dpTable[n - 1] < 0) {
			dpTable[n - 1] = memoization(n - 1);
		}
		
		if (dpTable[n - 3] < 0) {
			dpTable[n - 3] = memoization(n - 3);
		}
		
		long long int result = dpTable[n - 1] + dpTable[n - 3];
		dpTable[n] = result;

		return result;
	}
}

int main(void) {
	int n;

	cin >> n;

	dpTable = vector<long long int>(117, -1);
	//길이를 117로 설정: 범위가 1 <= n <= 116 이기 때문
	//그리고 -1로 초기화한다

	long long int result = memoization(n);

	/*for (int i = 0; i < dpTable.size(); i++) {
		cout << "n: " << n << ", dpTable[n]: " << dpTable[i] << endl;
	}*/

	cout << result << '\n';

	return 0;
}