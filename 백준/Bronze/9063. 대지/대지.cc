#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj9063
	"임씨의 이름이 새겨진 옥구슬이 나오는 모든 지점을 포함하는 
	가장 작은 남북, 동서 방향으로 평행한 변을 갖는 직사각형의 대지를 임씨의 소유로 인정한다.”
	임씨는 많은 손해를 보는 셈이지만 더 이상을 요구할 만한 근거가 없었기 때문에 이 판결을 따르기로 했다.

	임씨의 이름이 새겨진 옥구슬의 위치 N 개가 주어질 때에, 
	임씨에게 돌아갈 대지의 넓이를 계산하는 프로그램을 작성하시오. 
	단, 옥구슬의 위치는 2 차원 정수 좌표로 주어지고 옥구슬은 같은 위치에 여러 개가 발견될 수도 있으며,
	x 축의 양의방향을 동쪽, y 축의 양의방향을 북쪽이라고 가정한다.



	예를 들어 위와 같이 (2, 1), (3, 2), (5, 2), (3, 4) 네 점에서 옥구슬을 발견하였다면, 
	임씨에게 돌아갈 대지는 (2, 1), (5, 1), (2, 4), (5, 4)를 네 꼭짓점으로 하는 직사각형이며, 
	넓이는 (5 - 2) × (4 - 1) = 9 가 된다.
*/

int main(void) {
	int tCase;
	int xTmp, yTmp;
	vector<int> x;
	vector<int> y;
	int area;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> xTmp >> yTmp;

		x.push_back(xTmp);
		y.push_back(yTmp);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	if (tCase == 1) {
		cout << 0 << '\n';
	}
	else {
		area = (x[x.size()-1] - x[0])* (y[y.size()-1] - y[0]);
		cout << area << '\n';
	}

	return 0;
}