#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	string shortVer="";

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (i == 0) {
			shortVer += input[i];
		}

		else {
			if (input[i - 1] == '-') {
				shortVer += input[i];
			}
		}

	}

	cout << shortVer << '\n';

	return 0;
}