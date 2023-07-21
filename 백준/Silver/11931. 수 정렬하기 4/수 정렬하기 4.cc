#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int tCase;
	int tmp;
	vector<int> list;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		list.push_back(tmp);
	}

	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << '\n';
	}



	return 0;
}