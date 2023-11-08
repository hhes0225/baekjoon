#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int row, col;

vector<vector<int>> adjList;
vector<vector<int>> visited;

int numOfPainting=0, paintingSize=0;

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	//방문처리
	numOfPainting++;
	
	int tmpPaintingSize = 1;

	visited[y][x]=numOfPainting;

	//큐 생성, enqueue
	queue<pair<int, int>> qsearch;
	qsearch.push({ x, y });

	while(!qsearch.empty()){
		//큐에서 제거
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		//상하좌우 4방향 살펴보기
		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//맵 범위 이내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//그림 영역(1)이라면
				if (adjList[nextY][nextX] == 1) {
					//미방문 상태라면
					if (visited[nextY][nextX] == 0) {
						visited[nextY][nextX] = visited[here.second][here.first];
						//아니 미친 왜 할당연산자=가 아니라 비교연산자==를 쓰냐고
						tmpPaintingSize++;
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}

	paintingSize = max(paintingSize, tmpPaintingSize);
}

int main(void) {
	cin >> row >> col;

	adjList.resize(row);
	visited.resize(row);

	for (int i = 0; i < row; i++) {
		adjList[i] = vector<int>(col, 0);
		visited[i] = vector<int>(col, 0);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> adjList[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//미방문 상태면서 맵에 그림이 있는 영역일때
			if (visited[i][j] == 0 && adjList[i][j] == 1) {
				bfs(j, i);
			}
		}
	}

	cout << numOfPainting << "\n";
	cout << paintingSize << "\n";

	return 0;
}