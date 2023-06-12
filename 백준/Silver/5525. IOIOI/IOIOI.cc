#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int checkLength;
	string checkString = "";
	int strLength;
	string input;
	int duplicate = 0;

	cin >> checkLength >> strLength >> input;

	for (int i = 0; i <= checkLength * 2; i++) {
		if (i % 2 == 0) {
			checkString += 'I';
		}
		else {
			checkString += 'O';
		}
	}

	//cout << checkString << endl;
	
	for (int i = 0; i <= input.size() - checkString.size(); i++) {
		string tmp;
		tmp = input.substr(i, checkString.size());
		//cout << "i: " << i << ' ' << "end: " << i+checkString.size()<<' ';
		//cout << "tmp: " << tmp << endl;

		if (tmp == checkString)
			duplicate++;

	}

	cout << duplicate << '\n';


	return 0;
}