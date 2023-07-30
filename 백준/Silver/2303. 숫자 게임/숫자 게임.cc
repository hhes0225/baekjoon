#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int tCase;
	vector<int> scores;
	int personNum=0;
	int inputs[5] = {0, };
	int compare;
	int tmpScore=0;

	cin >> tCase;

	for (int i = 1; i <= tCase; i++) {
		scores.push_back(0);
	}

	for (int i = 0; i < scores.size(); i++) {
		cin >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3] >> inputs[4];
		int tmp = inputs[0] + inputs[1] + inputs[2] + inputs[3] + inputs[4];

		for (int j = 0; j < 5; j++) {
			for(int k = j + 1; k < 5; k++){
				compare = tmp - inputs[j] - inputs[k];
				tmpScore = max(tmpScore, compare%10);
			}
		}

		scores[i] = tmpScore;
		tmpScore = 0;
	}

	for (int i = 0; i < scores.size(); i++) {
		//cout << tmpScore << " " << scores[i] << endl;
		if (tmpScore < scores[i]) {
			personNum = i;
			tmpScore = scores[i];
		}
		else if (tmpScore == scores[i]) {
			personNum = i;
		}
	}

	cout << personNum + 1 << '\n';

	return 0;
}