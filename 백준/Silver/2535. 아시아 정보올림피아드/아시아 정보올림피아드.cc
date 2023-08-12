#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Score {
	int country;
	int stuNum;
	int stuScore;

public:
	Score(int country, int stuNum, int stuScore) {
		this->country = country;
		this->stuNum = stuNum;
		this->stuScore = stuScore;
	}

	int getCountry() {
		return country;
	}

	int getStuNum() {
		return stuNum;
	}

	int getStuScore() {
		return stuScore;
	}
};

bool compare(Score a, Score b) {
	return a.getStuScore() > b.getStuScore();
}

int main(void) {
	int tCase;
	int tmp1, tmp2, tmp3;
	vector<Score> scoreList;
	map<int, int> countryFreq;
	int rank = 0;

	bool isTwo = false;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;

		Score tmp = Score(tmp1, tmp2, tmp3);
		scoreList.push_back(tmp);
	}

	sort(scoreList.begin(), scoreList.end(), compare);

	/*cout << endl;
	for (int i = 0; i < scoreList.size(); i++) {
		cout << scoreList[i].getCountry() << " " << scoreList[i].getStuNum() << " " << scoreList[i].getStuScore() << endl;
	}*/

	
	for (int i = 0; i < scoreList.size(); i++) {
		if (rank == 3) {
			break;
		}
		
		if (countryFreq.find(scoreList[i].getCountry()) == countryFreq.end()) {
			countryFreq.insert(make_pair(scoreList[i].getCountry(), 1));
		}
		else {
			if (countryFreq[scoreList[i].getCountry()] >= 2) {
				continue;
			}
			else {
				countryFreq[scoreList[i].getCountry()]++;
			}
		}
		
		cout << scoreList[i].getCountry() << " " << scoreList[i].getStuNum() << '\n';
		rank++;
	}


	return 0;
}