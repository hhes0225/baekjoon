#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int row, col;

vector<vector<int>> miro;
vector<vector<int>>visited;

int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };

void bfs(int x, int y){
	// 첫 노드 방문처리
	visited[y][x]++;

	//첫 노드 큐에 삽입
	queue<pair<int, int>> qsearch;
	qsearch.push({ x, y });

	//반복문
	while (!qsearch.empty()) {
		//큐에서 dequeue(front pop)
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		//상하좌우 좌표이동 설정
		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//이동한 좌표가 이차원 배열(미로 맵) 범위 내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//미로 길이 있다면
				if (miro[nextY][nextX] == 1) {
					//방문하지 않았다면
					if (visited[nextY][nextX] == 0) {
						//방문처리
						visited[nextY][nextX] = visited[here.second][here.first] + 1;
						//큐에 삽입
						qsearch.push({ nextX, nextY });
					}
				}
			}
		 }



	}
}


int main(void) {
	cin >> row >> col;

	miro.resize(row);
	visited.resize(row);

	for (int i = 0; i < row; i++) {
		visited[i] = vector<int>(col, 0);
	}

	for (int i = 0; i < row; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			miro[i].push_back((int)input[j] - (int)'0');
		}
	}

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << miro[i][j] << " ";
		}
		cout << "\n";
	}*/

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (miro[i][j] == 1 && visited[i][j] == 0) {
				
			}
		}
	}*/

	bfs(0, 0);//x y 좌표는 col row 순이므로 반대 그치만 시작지점이 0, 0

	cout << visited[row - 1][col - 1] << "\n";//도착점 좌표의 visited 누적 출력


	return 0;
}