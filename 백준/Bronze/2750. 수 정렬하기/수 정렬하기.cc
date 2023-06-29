#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int tCase;
	int tmp;
	vector<int> numbers;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << '\n';
	}
		

	return 0;
}