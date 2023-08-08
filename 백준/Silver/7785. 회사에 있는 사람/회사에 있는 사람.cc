#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int tCase;
	string input;
	string name="";
	string situation="";
	map < string, bool, greater<string>> attend;
	vector<string> nameSort;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> name >> situation;

		if (situation == "enter") {
			attend.insert(make_pair(name, true));
		}
		else {
			//attend[name] = false;
			attend.erase(name);
		}

	}

	for (auto it = attend.begin(); it != attend.end(); it++) {
		if (it->second == true) {
			nameSort.push_back(it->first);
			//cout << it->first << '\n';
		}
	}
	 
	
	//대소문자 정렬이 안됨

	sort(nameSort.begin(), nameSort.end());
	reverse(nameSort.begin(), nameSort.end());

	for (int i = 0; i < nameSort.size(); i++) {
		cout << nameSort[i] << '\n';
	}


	return 0;
}