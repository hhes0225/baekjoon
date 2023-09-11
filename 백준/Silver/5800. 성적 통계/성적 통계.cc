#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int tCase;
	int subCase;
	int tmp;
	vector<int> scores;
	
	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> subCase;
		for (int j = 0; j < subCase; j++) {
			cin >> tmp;
			scores.push_back(tmp);
		}

		sort(scores.begin(), scores.end());

		int maxScore = scores[scores.size() - 1];
		int minScore = scores[0];
		int largestGap = 0;

		for (int j = 1; j < scores.size(); j++) {
			largestGap = max(largestGap, scores[j] - scores[j - 1]);
		}

		cout << "Class " << i + 1 << "\n";
		cout << "Max " << maxScore << ", Min " << minScore << ", Largest gap " << largestGap << '\n';

		scores.clear();
	}



	return 0;
}