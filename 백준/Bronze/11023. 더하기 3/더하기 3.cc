#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string input;
	string tmp = "";
	bool split = false;
	vector<int> numbers;
	int sum = 0;

	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			numbers.push_back(stoi(tmp));
			tmp = "";
			split = true;
			continue;
		}
		else {
			tmp += input[i];
		}
	}

	numbers.push_back(stoi(tmp));

	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}

	cout << sum << '\n';

	return 0;
}