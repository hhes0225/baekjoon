#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;

	//cin >> input;
	getline(cin, input);
	

	//cout << (int)'a' << " " << (int)'z' << " " << (int)'A' << " " << (int)'Z' << endl;

	for (int i = 0; i < input.size(); i++) {
		if ((input[i] >= 'A' && input[i] <= 'Z') && input[i] + 13 > 'Z') {
			//cout << "범위 넘어가는 대문자" << endl;
			cout << (char)((int)input[i] - ((int)'Z' - (int)'A') + 12);
		}
		else if ((input[i] >= 'a' && input[i] <= 'z') && input[i] + 13 > 'z') {
			//cout << "범위 넘어가는 소문자" << endl;
			cout << (char)((int)input[i] - ((int)'z' - (int)'a') + 12);
		}
		else if((input[i]>='A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
			//cout << "범위 안넘어가는 알파벳" << endl;
			cout << (char)((int)input[i] + 13); 
		}
		else {
			//cout << "알파벳 아님" << endl;
			cout << input[i];
		}
	}

	return 0;
}