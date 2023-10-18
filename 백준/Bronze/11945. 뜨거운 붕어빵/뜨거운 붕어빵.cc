#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

/*
	boj 11954


*/

int main(void) {
	int row, col;
	string tmp;
	vector<string> fishBread;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		cin >> tmp;
		fishBread.push_back(tmp);
	}

	for (int i = 0; i < fishBread.size(); i++) {
		reverse(fishBread[i].begin(), fishBread[i].end());
		cout << fishBread[i] << "\n";
	}

	return 0;
}