#include <iostream>
#include <vector>
#include <algorithm>
#define Problem 8

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}

bool compare2(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

int main(void) {
	vector<pair<int, int>>scores;
	vector<pair<int, int>> finalScore;

	for (int i = 0; i < Problem; i++) {
		int score;
		cin >> score;

		scores.push_back({ i + 1, score });
	}

	sort(scores.begin(), scores.end(), compare);

	int maxScore = 0;

	for (int i = 0; i < 5; i++) {
		finalScore.push_back(scores[i]);
		maxScore += scores[i].second;
	}

	cout << maxScore << "\n";

	sort(finalScore.begin(), finalScore.end());

	for (int i = 0; i < finalScore.size(); i++) {
		cout << finalScore[i].first << " ";
	}



	return 0;
}