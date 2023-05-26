#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	vector <int> alphabets;
	string input;

	for (int i = 0; i < 26; i++) {
		alphabets.push_back(-1);
	}

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		/*if (i >= 1) {
			if (input[i] == input[i - 1])
				continue;
		}*/
		if (alphabets[input[i] - (int)'a'] == -1)//알파벳 배열의 값이 -1이면 현재 위치 할당
			alphabets[input[i] - (int)'a'] = i;
		else
			continue;//그렇지 않다면 위치 할당 X
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabets[i] << " ";
	}

	return 0;
}