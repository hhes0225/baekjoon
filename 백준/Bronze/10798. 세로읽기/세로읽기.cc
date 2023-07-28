#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	string input;
	vector<string> words;
	int longestWord=0;

	for (int i = 0; i < 5; i++) {
		cin >> input;
		words.push_back(input);
	}


	//가장 긴 문자열 길이
	for (int i = 0; i < words.size(); i++) {
		longestWord = max((int)words[i].size(), longestWord);
	}

	//cout << longestWord << endl;

	for (int i = 0; i < longestWord; i++) {
		for (int j = 0; j < words.size(); j++) {
			if (words[j].size() < i || words[j][i]==NULL) {//NULL문자를 제거하지 않으면 에러가 난다.
				continue;
			}
			cout << words[j][i];
		}
	}

	cout << '\n';

	return 0;
}
