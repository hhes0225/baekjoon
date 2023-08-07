#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

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