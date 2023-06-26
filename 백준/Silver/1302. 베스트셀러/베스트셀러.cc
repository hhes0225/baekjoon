#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}


int main(void) {
	int tCase;
	string name;
	int sales;
	unordered_map<string, int> books;
	vector<pair<string, int>> bookVector;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> name;

		if (books.find(name) != books.end()) {//있으면
			books[name]++;
		}
		else {
			books.insert(make_pair(name, 1));
		}
	}
	
	//sort(books.begin(), books.end());

	for (auto it = books.begin(); it != books.end(); it++) {
		//cout << it->first << ", " << it->second << endl;
		bookVector.push_back(make_pair(it->first, it->second));
	}

	sort(bookVector.begin(), bookVector.end(), compare);

	/*for (int i = 0; i < bookVector.size(); i++) {
		cout << bookVector[i].first << ", " << bookVector[i].second << endl;
	}*/

	cout << bookVector[0].first << endl;

	return 0;
}