#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int tCase;
	int position;
	string input;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> position >> input;

		input.erase(input.begin() + position - 1);

		cout << input << '\n';
	}


	return 0;
}