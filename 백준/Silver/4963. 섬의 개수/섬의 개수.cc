#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	boj4963
	정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

	한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

	두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 
	지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
*/

vector<vector<int>> map;
vector<vector<bool>> visited;

int row, col;

int moveX[8] = { -1,1,0,0,-1,1, -1, 1 };
int moveY[8] = { 0,0,-1,1, -1,1,1,-1 };

void bfs(int x, int y) {
	//첫 노드 방문처리
	visited[y][x] = true;

	//큐 생성, enqueue
	queue<pair<int, int>> qsearch;
	qsearch.push({ x,y });

	while (!qsearch.empty()) {
		//큐에서 제거, dequeue
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//맵 범위 이내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//바다 영역이 아니라 land 영역이라면
				if (map[nextY][nextX] == 1) {
					//미방문 상태라면
					if (visited[nextY][nextX] == false) {
						visited[nextY][nextX] = true;
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}
}

int main(void) {

	while (1) {
		int numOfIsland = 0;
		cin >> col >> row;

		if (col == 0 && row == 0)
			break;

		map.resize(row);
		visited.resize(row);

		for (int i = 0; i < row; i++) {
			map[i] = vector<int>(col, 0);
			visited[i] = vector<bool>(col, false);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1 && visited[i][j] == false) {
					numOfIsland++;
					bfs(j, i);
				}
			}
		}

		cout << numOfIsland << '\n';

		map.clear();
		visited.clear();
	}

	return 0;
}