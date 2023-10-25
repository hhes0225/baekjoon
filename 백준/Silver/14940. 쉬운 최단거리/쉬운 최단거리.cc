#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;

int row, col;

int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	//첫 노드 방문처리
	visited[y][x] = 0;

	//큐에 삽입
	queue<pair<int, int>> qsearch;
	qsearch.push({ x, y });

	while (!qsearch.empty()) {
		//큐에서 제거
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		//노드 주변 상하좌우 순회
		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//상하좌우 위치가 맵 범위 이내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//맵 상으로 갈 수 있는 위치라면(map의 값이 1 = 갈 수 있음 / map의 값이 0 = 갈 수 없음)
				if (map[nextY][nextX] == 1) {
					//방문하지 않은 곳만 방문하겠다
					if (visited[nextY][nextX] == -2) {
						visited[nextY][nextX] = visited[here.second][here.first] + 1;
						qsearch.push(make_pair(nextX, nextY));
					}
				}
			}
		}
	}

 }

int main(void) {
	cin >> row >> col;

	map.resize(row);
	visited.resize(row);

	for (int i = 0; i < row; i++) {
		map[i] = vector<int>(col, 0);
		visited[i] = vector<int>(col, -2);
	}

	int startX=0, startY=0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				startX = j;
				startY = i;
			}
		}
	}

	bfs(startX, startY);

	//후처리
	//갈 수 없는 땅은 -2이었는데 0으로 바꾸어준다
	//갈 수 있지만 막혀서 못가는 땅은 0이었는데 -1로 바꾸어준다.
	//이때, 시작점은 제외한다.

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == -2 && map[i][j] != 0) {
				visited[i][j] = -1;
			}
			else if (visited[i][j] == -2) {
				visited[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}