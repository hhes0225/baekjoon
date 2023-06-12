#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main(void) {
	int tCase;
	int tmpX, tmpY;
	vector <pair<int, int>> axis;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmpX >> tmpY;

		axis.push_back(make_pair(tmpX, tmpY));
	}

	sort(axis.begin(), axis.end(), compare);

	for (int i = 0; i < axis.size(); i++) {
		cout << axis[i].first << ' ' << axis[i].second << '\n';
	}

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}