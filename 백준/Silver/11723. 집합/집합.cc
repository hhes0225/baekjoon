#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
	boj 11723 집합
	비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

	add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
	remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
	check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
	toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
	all: S를 {1, 2, ..., 20} 으로 바꾼다.
	empty: S를 공집합으로 바꾼다.
*/

int main(void) {
	int tCase;
	string command;
	int num;
	unordered_map<int, bool> set;

	for (int i = 1; i <= 20; i++) {
		set.insert(make_pair(i, false));
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> tCase;
	cin.ignore();

	for (int i = 0; i < tCase; i++) {
		getline(cin, command);

		if (command.find(' ') != string::npos) {
			/*cout << "공백있음" << endl;
			cout << command.find(' ')<<endl;*/

			num = stoi(command.substr(command.find(' ') + 1, command.size() - 1));
			//cout << num << endl;
		}
		
		if (command.find("add") != string::npos) {
			set[num] = true;
		}
		else if (command.find("remove") != string::npos) {
			set[num] = false;
		}
		else if (command.find("check") != string::npos) {
			if (set[num]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (command.find("toggle") != string::npos) {
			if (set[num]) {
				set[num] = false;
			}
			else {
				set[num] = true;
			}
		}
		else if (command.find("all") != string::npos) {
			for (auto it = set.begin(); it != set.end(); it++) {
				it->second = true;
			}
		}
		else if (command.find("empty") != string::npos) {
			for (auto it = set.begin(); it != set.end(); it++) {
				it->second = false;
			}
		}

	}



	return 0;
}#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
	boj 11723 집합
	비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

	add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
	remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
	check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
	toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
	all: S를 {1, 2, ..., 20} 으로 바꾼다.
	empty: S를 공집합으로 바꾼다.
*/

int main(void) {
	int tCase;
	string command;
	int num;
	unordered_map<int, bool> set;

	for (int i = 1; i <= 20; i++) {
		set.insert(make_pair(i, false));
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> tCase;
	cin.ignore();

	for (int i = 0; i < tCase; i++) {
		getline(cin, command);

		if (command.find(' ') != string::npos) {
			/*cout << "공백있음" << endl;
			cout << command.find(' ')<<endl;*/

			num = stoi(command.substr(command.find(' ') + 1, command.size() - 1));
			//cout << num << endl;
		}
		
		if (command.find("add") != string::npos) {
			set[num] = true;
		}
		else if (command.find("remove") != string::npos) {
			set[num] = false;
		}
		else if (command.find("check") != string::npos) {
			if (set[num]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (command.find("toggle") != string::npos) {
			if (set[num]) {
				set[num] = false;
			}
			else {
				set[num] = true;
			}
		}
		else if (command.find("all") != string::npos) {
			for (auto it = set.begin(); it != set.end(); it++) {
				it->second = true;
			}
		}
		else if (command.find("empty") != string::npos) {
			for (auto it = set.begin(); it != set.end(); it++) {
				it->second = false;
			}
		}

	}



	return 0;
}
