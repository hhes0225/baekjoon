#include <iostream>
#include <vector>

using namespace std;

//0에서부터 9까지의 숫자로 이루어진 N개의 숫자가 나열된 수열이 있다.
//그 수열 안에서 연속해서 커지거나(같은 것 포함), 
//혹은 연속해서 작아지는(같은 것 포함) 수열 중 가장 길이가 긴 것을 찾아내어 그 길이를 출력하는 프로그램을 작성하라.
//
//예를 들어 수열 1, 2, 2, 4, 4, 5, 7, 7, 2 의 경우에는 
//1 ≤ 2 ≤ 2 ≤ 4 ≤ 4 ≤ 5 ≤ 7 ≤ 7 이 가장 긴 구간이 되므로 그 길이 8을 출력한다.
//
//수열 4, 1, 3, 3, 2, 2, 9, 2, 3 의 경우에는 
//3 ≥ 3 ≥ 2 ≥ 2 가 가장 긴 구간이 되므로 그 길이 4를 출력한다.
//
//또 1, 5, 3, 6, 4, 7, 1, 3, 2, 9, 5 의 경우에는 
//연속해서 커지거나 작아지는 수열의 길이가 3 이상인 경우가 없으므로 2를 출력하여야 한다.
//
//해결방법
//- 같을 때가 가장 문제였다. 증가모드? 감소모드? 나누지 않고
//그냥 크거나 같으면 증가 +1, 작거나 같으면 감소+1했다.
//그리고 그렇지 않으면 리셋

//반례
//INPUT : 1 1
//OUTPUT: 0(정답은 1)
//
//INPUT : 5 1 1 1 1 1
//OUTPUT: 0(정답은 5)
//
//INPUT: 5 3 1 1 1 1
//OUTPUT : 1(정답은 5)

int tabulation(vector<int> numbers) {
	int increasing = 1;//i==0일때, 숫자 일단 +1해주기
	int decreasing = 1;//i==0일때, 숫자 일단 +1해주기
	int maxIncreasing = 0;
	int maxDecreasing = 0;
	bool isIncreasing=false;


	if (numbers.size() == 1) {
		maxIncreasing = 1;
		maxDecreasing = 1;
	}

	for (int i = 1; i < numbers.size(); i++) {

		if (numbers[i - 1] >= numbers[i]) {
			increasing++;
		}
		else {
			maxIncreasing = max(maxIncreasing, increasing);
			increasing = 1;
		}

		if (numbers[i - 1] <= numbers[i]) {
			decreasing++;
		}
		else {
			maxDecreasing = max(maxDecreasing, decreasing);
			decreasing = 1;
		}
	}

	//마지막에 else문으로 안들어가서 반영 안된 경우 강제로 반영하기
	maxIncreasing = max(maxIncreasing, increasing);
	maxDecreasing = max(maxDecreasing, decreasing);

	return max(maxIncreasing, maxDecreasing);
}

int main(void) {
	int tCase;
	int tmp;
	vector<int> numbers;
	int longestSequence;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	longestSequence = tabulation(numbers);

	cout << longestSequence << '\n';

	return 0;
}