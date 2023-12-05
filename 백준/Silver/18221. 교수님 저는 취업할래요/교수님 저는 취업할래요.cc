#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
	boj 18221
	성규는 학점이 높고 알고리즘도 잘 다루는 편이라 매년 알고리즘 대회에 나가 수상을 해오곤 한다. 
	성규의 꿈은 대학교 4학년 칼졸업을 하고 나서 좋은 대기업에 취직하여 빨리 돈을 버는 것이다.

	어느 날, 성규는 전공 수업을 들으러 강의실에 가서 책을 펴고 앉았다. 
	이 때 교수님이 수업을 시작하시기 전에 한 말씀 하셨다.

	교수님: "음... 여기서 내가 눈 여겨 봐온 학생이 있는데... 그래, 성규야. 너 내 랩실에 들어올 생각 없니? 
	나와 함께 알고리즘에 대한 논문이나 써보자꾸나."

	성규는 큰일이다 싶었다. 성규는 졸업하고 싶었다. 
	대답을 할 생각이 떠오르기 전에 먼저 도망가야겠다는 생각이 들어버렸다!

	강의실에는 가로로 N 행, 세로로 N 열, 총 N × N 개의 책상이 있으며,
	위쪽에서부터 R 번째 행, 왼쪽에서부터 C 번째 열에 있는 책상의 위치를 (R, C)로 표현한다. 
	각 책상 자리는 비어있거나, 성규가 아닌 학생 혹은 성규가 앉아있거나, 교수님이 위치해 있다.

	도망가는 데 성공하려면, 성규와 교수님의 거리가 5 이상이면서, 
	교수님과 성규를 꼭짓점으로 하는 축에 평행한 직사각형 안에, 
	교수님을 제지해줄 성규가 아닌 학생이 세 명 이상 있어야 한다.
	단, 교수님과 성규가 같은 행 혹은 같은 열의 책상에 앉아있다면 
	교수님과 성규를 잇는 선분 상에 성규가 아닌 학생이 세 명 이상 있어야 한다.

	이때, 책상 (a, b)와 책상 (c, d) 간의 거리는
	$\sqrt{(a-c)^2 + (b-d)^2}$로 정의한다.

	성규는 도망가다가 잡히는 것이 최악이라 판단되어, 
	도망갈 수가 없는 환경이면 순순히 대학원생의 길로 들어서려고 한다. 
	이런 성규를 위해 확실히 도망갈 수 있는지 알려주는 프로그램을 작성하자.
*/

int main(void) {
	int mapSize;
	vector<vector<int>> map;
	pair<int, int> prof, seongyu;
	vector<pair<int, int>> others;
	int runaway;
	int otherinArea = 0;

	cin >> mapSize;
	
	map.resize(mapSize);

	for (int i = 0; i < mapSize; i++) {
		map[i].resize(mapSize);
	}

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> map[i][j];

			if (map[i][j] == 5) {
				prof.first = j;
				prof.second = i;
			}
			else if (map[i][j] == 2) {
				seongyu.first = j;
				seongyu.second = i;
			}
			else if (map[i][j] == 1) {
				pair<int, int>tmp;
				tmp.first = j;
				tmp.second = i;

				others.push_back(tmp);
			}
		}
	}

	double distance;
	distance = sqrt(pow((prof.first - seongyu.first), 2) + pow((prof.second - seongyu.second), 2));

	//cout << distance << endl;

	if (distance >= 5) {
		for (int i = 0; i < others.size(); i++) {
			if ((others[i].first >= min(prof.first, seongyu.first) && others[i].first <= max(prof.first, seongyu.first)) &&
				(others[i].second >= min(prof.second, seongyu.second) && others[i].second <= max(prof.second, seongyu.second))) {
				otherinArea++;

			}
		}

		if (otherinArea >= 3) {
			runaway = 1;
		}
		else
			runaway = 0;
	}
	else {
		runaway = 0;
	}

	cout << runaway << endl;


	return 0;
}