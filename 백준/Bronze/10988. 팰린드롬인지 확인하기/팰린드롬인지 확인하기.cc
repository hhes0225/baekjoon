#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	bool isPel=true;

	cin >> input;

	for (int i = 0; i < input.size() / 2; i++) {
		if (input[i] == input[input.size() - 1 - i]) {
			continue;
		}
		else {
			isPel = false;
		}

	}

	cout << isPel << '\n';

	return 0;
}