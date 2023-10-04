#include <iostream>
#include <vector>
using namespace std;

/*
	boj17247
	택시 거리는 바둑판 모양의 도로망을 가진 도시에서
	점 A에서 B까지의 최단 거리를 구할 경우 도로를 따라서만 가는 가장 짧은 거리를 뜻한다.

	위의 사진에서는 빨간색 선이 택시거리이다. 
	즉, 점 A의 좌표가 (x1, y1)이고 점 B의 좌표를 (x2, y2)라고 했을 때, 
	두 장소 사이의 택시 거리 D는 다음과 같다.

 
	D = |x_2 - x_1| + |y_2 - y_1|

	인접한 0과 0, 0과 1, 1과 1 사이의 거리를 1이라고 할 때, 두 1 사이의 거리를 구하는 프로그램을 작성하시오.
*/

int main(void) {
	int height, width;
	int input;
	vector<vector<int>> distanceMap;
	vector<pair<int, int>> points;

	cin >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> input;

			if (input == 1) {
				points.push_back(make_pair(i, j));
			}
		}
	}

	int distanceX = (points[1].first - points[0].first) > 0 ? points[1].first - points[0].first : -(points[1].first - points[0].first);
	int distanceY = (points[1].second - points[0].second) > 0 ? points[1].second - points[0].second : -(points[1].second - points[0].second);

	cout << distanceX + distanceY << '\n';

	return 0;
}