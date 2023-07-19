#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
	int tCase;
	int input;
	map<int, int> numbers;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		if (numbers.find(input) != numbers.end()) {//있으면
			numbers[input]++;
		}
		else {//없으면
			numbers.insert(make_pair(input, 1));
		}
	}

	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		cout << it->first << ' ';
	}

	cout << '\n';


	return 0;
}