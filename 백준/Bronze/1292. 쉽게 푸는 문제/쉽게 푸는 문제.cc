#include <iostream>
#include <vector>

using namespace std;

/*
	boj 1292
	동호는 내년에 초등학교를 입학한다. 
	그래서 동호 어머니는 수학 선행 학습을 위해 쉽게 푸는 문제를 동호에게 주었다.

	이 문제는 다음과 같다. 
	1을 한 번, 2를 두 번, 3을 세 번, 이런 식으로 1 2 2 3 3 3 4 4 4 4 5 .. 
	이러한 수열을 만들고 어느 일정한 구간을 주면 그 구간의 합을 구하는 것이다.

	하지만 동호는 현재 더 어려운 문제를 푸느라 바쁘기에 우리가 동호를 도와주자.
*/

int main(void) {
	int from, to;
	vector<int> numbers;
	int sum = 0;

	cin >> from >> to;

	for (int i = 1; i <= to; i++) {
		for (int j = 0; j < i; j++) {
			numbers.push_back(i);
		}
	}

	for (int i = from - 1; i < to; i++) {
		//cout << numbers[i] << endl;

		sum += numbers[i];
	}

	cout << sum << endl;

	return 0;
}