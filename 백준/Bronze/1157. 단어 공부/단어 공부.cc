#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int alphabet[26] = { 0, };
	string input;
	int maxAlphaIdx = 0;
	bool isDuplicated = false;

	/*cout << (int)'a' << endl;
	cout << (int)'A' << endl;*/

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if ((int)input[i] < (int)'a') {//uppercase
			alphabet[(int)input[i]-(int)'A']++;
		}
		else {//lower
			alphabet[(int)input[i]-(int)'a']++;
		}
	}

	/*for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << endl;
	}*/

	for (int i = 1; i < 26; i++) {
		//cout << "alphabet[i] = "<< alphabet[i]<<", alphabet[max]: "<<alphabet[maxAlphaIdx] << endl;
		if (alphabet[i] > alphabet[maxAlphaIdx]) {
			maxAlphaIdx = i;
			isDuplicated = false;
		}
		else if (alphabet[i] == alphabet[maxAlphaIdx] && alphabet[maxAlphaIdx]!=0) {
			isDuplicated = true;
		}
		else {
			continue;
		}
	}

	//cout << maxAlphaIdx << endl;;

	if (!isDuplicated) {
		/*cout << (maxAlphaIdx) << endl;
		cout << ((int)'A') << endl;*/
		cout << (char)(maxAlphaIdx + (int)'A') << endl;
	}
	else {
		cout << "?" << endl;
	}


	return 0;
}