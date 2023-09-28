#include <iostream>
#include <vector>
using namespace std;

/*
	boj4344

	대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

	첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

	둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 
	점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*/

int main(void) {
	int tCase;


	cin >> tCase;

	for (int i = 0; i < tCase; i++) {

		int stuNum;
		double scoreInput;
		vector<double> scores;
		double scoreSum = 0;
		double scoreAvg;
		int overAvg = 0;

		cin >> stuNum;

		for (int j = 0; j < stuNum; j++) {
			cin >> scoreInput;

			scores.push_back(scoreInput);
			scoreSum += scoreInput;
		}

		scoreAvg = scoreSum / (double)stuNum;

		//cout << scoreAvg << '\n';

		for (int j = 0; j < stuNum; j++) {
			if (scoreAvg < scores[j]) {
				overAvg++;
			}
		}

		double overAvgRatio = ((double)overAvg / (double)stuNum) * 100;

		//cout << overAvgRatio << '\n';

		printf("%.3lf", overAvgRatio);
		cout << "%\n";

	}


	return 0;
}