#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string input;
	vector<char> cambridge = { 'C', 'A', 'M','B','R','I','D','G','E' };
	vector<char> inputChar;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		inputChar.push_back(input[i]);
	}

	for (int i = 0; i < cambridge.size(); i++) {
		while(find(inputChar.begin(), inputChar.end(), cambridge[i]) != inputChar.end()){
			if (find(inputChar.begin(), inputChar.end(), cambridge[i]) != inputChar.end()) {//존재하면
				inputChar.erase(find(inputChar.begin(), inputChar.end(), cambridge[i]), find(inputChar.begin(), inputChar.end(), cambridge[i])+1);
			}
		}
	}

	for (int i = 0; i < inputChar.size(); i++) {
		cout << inputChar[i];
	}
	

	return 0;
}