#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
	boj1755
	79를 영어로 읽되 숫자 단위로 하나씩 읽는다면 "seven nine"이 된다. 
	80은 마찬가지로 "eight zero"라고 읽는다. 
	79는 80보다 작지만, 영어로 숫자 하나씩 읽는다면 "eight zero"가 "seven nine"보다 사전순으로 먼저 온다.

	문제는 정수 M, N(1 ≤ M ≤ N ≤ 99)이 주어지면 M 이상 N 이하의 정수를 숫자 하나씩 읽었을 때를 기준으로 사전순으로 정렬하여 출력하는 것이다.
*/

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

int main(void) {
	int from, to;
	vector<int> num;
	vector<pair<string, int>> numStr;
	vector<int> result;

	cin >> from >> to;

	//num.resize(to - from + 1);
	//numStr.resize(to - from + 1);


	//num 벡터 세팅
	for (int i = from; i <= to; i++) {
		num.push_back(i);
	}


	//numStr 벡터 세팅(정수에서 스트링으로 변환)
	for (int i = 0; i < num.size(); i++) {
		string tmp;
		string origin = to_string(num[i]);
		for (int j = 0; j < origin.size(); j++) {
			if (origin[j] == '0') {
				tmp+="zero";
			}
			else if (origin[j] == '1') {
				tmp += "one";
			}
			else if (origin[j] == '2') {
				tmp += "two";
			}
			else if (origin[j] == '3') {
				tmp += "three";
			}
			else if (origin[j] == '4') {
				tmp += "four";
			}
			else if (origin[j] == '5') {
				tmp += "five";
			}
			else if (origin[j] == '6') {
				tmp += "six";
			}
			else if (origin[j] == '7') {
				tmp += "seven";
			}
			else if (origin[j] == '8') {
				tmp += "eight";
			}
			else if (origin[j] == '9') {
				tmp += "nine";
			}
		}

		numStr.push_back({ tmp, num[i] });
	}


	/*for (int i = 0; i < numStr.size(); i++) {
		cout << numStr[i] << " ";
	}*/

	sort(numStr.begin(), numStr.end(), compare);

	for (int i = 0; i < numStr.size(); i++) {
		cout << numStr[i].second << " ";

		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	

	return 0;
}