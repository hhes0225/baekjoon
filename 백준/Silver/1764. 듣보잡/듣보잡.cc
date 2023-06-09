#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int hearCase, seeCase;
	string tmpName;
	//int notHeardSeen = 0;
	unordered_map<string, int> notHeardSeen;
	int numOfHS = 0;
	vector<string> nameHS;


	cin >> hearCase >> seeCase;

	for (int i = 0; i < (hearCase + seeCase);i++) {
		cin >> tmpName;

		if (notHeardSeen.find(tmpName) != notHeardSeen.end()) {
			notHeardSeen[tmpName]++;
		}
		else {
			notHeardSeen.insert(make_pair(tmpName, 1));
		}
	}

	/*for (int i = 0; i < hearCase; i++) {
		cin >> tmpName;
		notHeard.insert(make_pair(tmpName, 1));
	}


	for (int i = 0; i < seeCase; i++) {
		cin >> tmpName;
		notSeen.insert(make_pair(tmpName, 1));
	}*/

	for (auto i = notHeardSeen.begin(); i != notHeardSeen.end(); i++) {
		if (i->second == 2) {
			numOfHS++;
			nameHS.push_back(i->first);
		}
	}

	sort(nameHS.begin(), nameHS.end());

	cout << numOfHS << endl;
	for (int i = 0; i < nameHS.size(); i++) {
		cout << nameHS[i] << endl;
	}

	return 0;
}