#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
	boj1485
	네 점이 주어졌을 때, 네 점을 이용해 정사각형을 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
	각 테스트 케이스는 네 줄로 이루어져 있으며, 점의 좌표가 한 줄에 하나씩 주어진다. 
	점의 좌표는 -100,000보다 크거나 같고, 100,000보다 작거나 같은 정수이다. 
	같은 점이 두 번 이상 주어지지 않는다.

	출력
	각 테스트 케이스마다 입력으로 주어진 네 점을 이용해서 정사각형을 만들 수 있으면 1을, 없으면 0을 출력한다.
*/

/*
	정사각형의 정의
	모든 변의 길이가 같다.
	모든 대각선의 길이가 같다.
*/

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int length(pair<int, int> a, pair<int, int> b) {
	return (pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(void) {
	int tCase;
	vector<pair<int, int>> points;

	cin >> tCase;


	for (int i = 0; i < tCase; i++) {
		bool isSquare = false;
		points.resize(4);

		for (int j = 0; j < 4; j++) {
			cin >> points[j].first >> points[j].second;
		}

		sort(points.begin(), points.end(), compare);

		/*for (int j = 0; j < 4; j++) {
			cout << points[j].first << " " << points[j].second << endl;
		}*/

		int a = length(points[0], points[1]);//가로 밑
		int b = length(points[0], points[2]);//세로 왼
		int c = length(points[0], points[3]);//세로 오
		int d = length(points[1], points[2]);//가로 위
		int e = length(points[1], points[3]);//가로 위
		int f = length(points[2], points[3]);//가로 위

		vector<int> lengths;

		lengths.push_back(a);
		lengths.push_back(b);
		lengths.push_back(c);
		lengths.push_back(d);
		lengths.push_back(e);
		lengths.push_back(f);

		sort(lengths.begin(), lengths.end());
		//가장 긴 두 변이 대각선

		//cout << lengths[0] << " " << lengths[1] << " " << lengths[2] << " " << lengths[3] << " " << lengths[4] << " " << lengths[5] << endl;

		if (lengths[0]== lengths[1]&& lengths[1] == lengths[2]&& lengths[2] == lengths[3]&& lengths[3] == lengths[1]&& lengths[4] == lengths[5]) {
			isSquare = true;
		}

		if(isSquare)
			cout << 1 << endl;
		else
			cout << 0 << endl;

		points.clear();

	}

	return 0;
}