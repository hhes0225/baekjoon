#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	//이중포문은 O(n^2)->10만개 data라면 10만^2 = 100억개 연산 수행 필요->100초 소요
	//https://lemonlemon.tistory.com/54
	

	//시간초과 방지?
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int totalNum;
	int tryCount;
	vector<int> numbers;
	vector<int> sums;
	int input;
	int front, back;//구간
	int result = 0;

	cin >> totalNum;
	cin >> tryCount;

	for (int i = 0; i < totalNum; i++) {
		cin >> input;
		numbers.push_back(input);

		if (i == 0)
			sums.push_back(input);
		else {
			sums.push_back(input + sums[i - 1]);
		}
	}

	/*for (int i = 0; i < totalNum; i++) {
		cout << numbers[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < totalNum; i++) {
		cout << sums[i] << " ";
	}

	cout << endl;*/

	for (int i = 0; i < tryCount; i++) {
		cin >> front;
		cin >> back;

		/*
		*	이러면 O(n^2)이 되어서 시간초과
			for (int j = front - 1; j < back; j++) {
			result += numbers[j];
		}*/

		if (back==front)
			result = numbers[back - 1];
		else if (front - 1 <= 0)
			result = sums[back - 1];
		else{
			result = sums[back - 1] - sums[front - 1 -1];
		}

		if (i < tryCount - 1) {
			cout << result << "\n";
			result = 0;
		}
		else
			cout << result;
	}



	return 0;
}