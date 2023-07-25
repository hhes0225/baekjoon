#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int tCase;
	string input;
	string copy;
	bool groupWord = true;
	int numOfgroupWord = 0;

	cin >> tCase;


	for (int i = 0; i < tCase; i++) {

		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			copy = input.substr(j + 1, input.size() - 1);
			//cout << "copy: " << copy << endl;
			//cout << "input[j]: " << input[j] << endl;

			if (copy.find(input[j])!=string::npos) {
				//cout << "found\n";

				if (copy[0] != input[j]) {
					groupWord = false;
					break;
				}
			}
		}

		if (groupWord) {
			numOfgroupWord++;
		}

		groupWord = true;

	}

	cout << numOfgroupWord << '\n';


	return 0;
}