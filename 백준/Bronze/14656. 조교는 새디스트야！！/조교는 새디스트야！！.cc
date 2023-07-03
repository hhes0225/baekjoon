#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int tCase;
	int tmp;
	vector<int> list;
	int wrong = 0;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		list.push_back(tmp);
	}

	for (int i = 0; i < list.size(); i++) {
		if (i + 1 == list[i]) {
			continue;
		}

		wrong++;
	}


	cout << wrong << '\n';
	return 0;
}