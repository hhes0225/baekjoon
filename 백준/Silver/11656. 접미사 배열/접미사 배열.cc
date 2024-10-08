#include <iostream>
#include <vector>
#include<algorithm>
#include <string>

using namespace std;

/*
	boj11656
	접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.
	
	baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 
	이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.

	문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.
*/

int main(void) {
	string input;
	string tmp;
	vector<string> suffix;

	cin >> input;


	for (int i = 0; i < input.size(); i++) {
		tmp = input.substr(i, input.size());
		suffix.push_back(tmp);
		//cout << tmp << endl;
	}

	sort(suffix.begin(), suffix.end());

	for (int i = 0; i < input.size(); i++) {
		cout << suffix[i] << '\n';
	}

	return 0;
}