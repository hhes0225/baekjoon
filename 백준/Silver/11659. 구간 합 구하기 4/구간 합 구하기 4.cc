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
		// for문으로 합 구하면 이중 포문 되어서 시간 초과 나니까
		// 미리 누적합을 구해놓는다.
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
			//구간별 누적값: 미리 구해놓은 누적값 - 이전 누적값
			// ex) 3~5번째의 합 = 1~5번째 누적합 - 1~2번째 누적합
			// 이렇게 하면 for문을 쓰지 않고 누적합을 구할 수 있다.
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
