#include <iostream>
#include <vector>

using namespace std;

/*
	boj 1085
	한수는 지금 (x, y)에 있다. 
	직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 
	직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

	풀이:
	대각선은 고려하지 않아도 되는 것 같으므로,
	x-0, y-0, w-x, h-y 의 최소값이 거리의 최소값이라고 설정했다.
*/

int main(void) {
	int x, y, w, h;
	int minDistance = 999999;
	vector<int> findMin;
	
	cin >> x >> y >> w >> h;

	findMin.push_back(x);
	findMin.push_back(y);
	findMin.push_back(w-x);
	findMin.push_back(h-y);

	for (int i = 0; i < findMin.size(); i++) {
		minDistance = min(minDistance, findMin[i]);
	}

	cout << minDistance << '\n';


	return 0;
}