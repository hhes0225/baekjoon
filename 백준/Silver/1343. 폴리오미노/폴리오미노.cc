#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string input;
	string tmp="";
	vector<string> split;
	bool possible = true;

	cin >> input;

	for (int i = 0; i < input.size(); i++){
		if (tmp=="") {
			tmp += input[i];
			continue;
		}

		if (tmp[0] == 'X') {
			if (input[i] == 'X') {
				tmp += input[i];
				continue;
			}
			else {
				split.push_back(tmp);
				tmp.clear();
				tmp += input[i];
				continue;
			}
		}
		else {
			if (input[i] == '.') {
				tmp += input[i];
				continue;
			}
			else {
				split.push_back(tmp);
				tmp.clear();
				tmp += input[i];
				continue;
			}
		}
	}

	split.push_back(tmp);


	//test
	/*for (int i = 0; i < split.size(); i++) {
		cout << split[i] << '\n';
	}*/

	for (int i = 0; i < split.size(); i++) {
		if (split[i][0] == 'X') {
			if (split[i].size() % 2 == 1) {
				possible = false;
				break;
			}

			if (split[i].size() == 2) {
				split[i] = "BB";
			}
			else {
				tmp.clear();
				for (int j = 0; j < split[i].size() / 4; j++) {
					tmp += "AAAA";
				}

				if (split[i].size() % 4 == 2) {
					tmp += "BB";
				}

				split[i] = tmp;
			}
		}
		else {
			continue;
		}
	}

	if (!possible) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < split.size(); i++) {
			cout << split[i];
		}

		cout << '\n';
	}

	return 0;
}