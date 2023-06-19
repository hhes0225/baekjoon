#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int tCase, tSet;
	string tmp;
	unordered_map<string, int> contained;
	vector<string> stringSets;
	int sum = 0;

	cin >> tCase >> tSet;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		contained.insert(make_pair(tmp, 0));
	}

	for (int i = 0; i < tSet; i++) {
		cin >> tmp;
		if (contained.find(tmp) != contained.end()) {
			//cout << "find" << endl;
			contained[tmp]++;
		}
	}

	for (auto it = contained.begin(); it != contained.end(); it++) {
		sum += it->second;
	}

	cout << sum << endl;



	return 0;
}