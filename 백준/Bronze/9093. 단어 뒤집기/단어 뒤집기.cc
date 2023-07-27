#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int tCase;
	string tmp;
	string split;
	vector<string> input;

	cin >> tCase;

	cin.ignore();

	for (int i = 0; i < tCase; i++) {
		getline(cin, tmp);
		
		//스페이스바 기준으로 split하여 input에 넣기
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == ' ') {
				input.push_back(split);
				split = "";
				continue;
			}

			split += tmp[j];
		}

		input.push_back(split);

		for (int j = 0; j < input.size(); j++) {
			reverse(input[j].begin(), input[j].end());

			cout << input[j] << " ";
		}

		cout << '\n';
		input.clear();
		tmp = "";
		split = "";
	}

	return 0;
}