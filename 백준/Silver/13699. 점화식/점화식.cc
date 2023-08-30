#include <iostream>

using namespace std;
#define MAX 35

unsigned long long int memo[MAX + 1] = { 0, };


//다음의 점화식에 의해 정의된 수열 t(n)을 생각하자 :
//
//t(0) = 1
//t(n) = t(0) * t(n - 1) + t(1) * t(n - 2) + ... + t(n - 1) * t(0)
//이 정의에 따르면,
//
//t(1) = t(0) * t(0) = 1
//t(2) = t(0) * t(1) + t(1) * t(0) = 2
//t(3) = t(0) * t(2) + t(1) * t(1) + t(2) * t(0) = 5
//...
//주어진 입력 0 ≤ n ≤ 35에 대하여 t(n)을 출력하는 프로그램을 작성하시오.

unsigned long long int memoization(unsigned long long int n) {
	//cout << "!!!!!!!!!!!!! " << n << " !!!!!!!!!!\n";
	unsigned long long int result=0;

	if (n == 0) {
		//cout << "t(0) = 1\n";
		return 1;
	}
	else if (n == 1) {
		//cout << "t(1) = 2\n";
		return 1;
	}

	//memo 테이블의 값이 0이다: 값이 아무것도 저장되지 않았다.
	//memo 테이블의 값이 0 이상이다: 무언가 이전에 값을 저장해놓았다.
	//왜냐면 t(n)의 결과는 항상 자연수이기 때문
	if (memo[n] > 0){
		//cout << "memo["<<n<<"]: "<<memo[n]<<'\n';
		return memo[n];
	}

	for (unsigned long long int i = 0; i < n; i++) {
		//cout << "i: " << i << ", n-1-i: " << n-1-i << '\n';
		result += memoization(i) * memoization(n - 1 - i);

		//cout << "result: " << result << '\n';
	}

	memo[n] = result;

	return result;

}

int main(void) {
	unsigned long long int tCase;
	unsigned long long int result;

	cin >> tCase;

	result = memoization(tCase);

	cout << result << '\n';

	return 0;
}