#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//최근 아시아 지역의 학생들만 참여하는 정보 올림피아드 대회가 만들어졌다.
//이 대회는 온라인으로 치러지기 때문에 각 나라에서 이 대회에 참여하는 학생 수의 제한은 없다.
//
//참여한 학생들의 성적순서대로 세 명에게만 금, 은, 동메달을 수여한다.
//단, 동점자는 없다고 가정한다.그리고 나라별 메달 수는 최대 두 개다.
//
//대회 결과가 입력으로 주어질 때, 메달 수상자를 결정하여 출력하는 프로그램을 작성하시오.

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
