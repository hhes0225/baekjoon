#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

/*
	boj 21736
	2020년에 입학한 헌내기 도연이가 있다. 도연이는 비대면 수업 때문에 학교에 가지 못해 학교에 아는 친구가 없었다. 드디어 대면 수업을 하게 된 도연이는 어서 캠퍼스 내의 사람들과 친해지고 싶다.

	도연이가 다니는 대학의 캠퍼스는 N times M 크기이며 캠퍼스에서 이동하는 방법은 벽이 아닌 상하좌우로 이동하는 것이다. 
	예를 들어, 도연이가 (x, y)에 있다면 이동할 수 있는 곳은 (x+1, y), (x, y+1), (x-1, y), (x, y-1)이다. 
	단, 캠퍼스의 밖으로 이동할 수는 없다.

	불쌍한 도연이를 위하여 캠퍼스에서 도연이가 만날 수 있는 사람의 수를 출력하는 프로그램을 작성해보자.
*/

int row, col;
vector <string> map;
vector<vector<bool>> visited;

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

int meetingPeople = 0;

void bfs(int x, int y) {
	//방문처리
	visited[y][x] = true;

	//큐 enqueue
	queue<pair<int, int>> qsearch;
	qsearch.push({ x,y });

	while (!qsearch.empty()) {
		//dequeue
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//맵 범위 이내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//벽이 아니라 갈 수 있는 곳이라면
				if (map[nextY][nextX] == 'O' || map[nextY][nextX] == 'P') {
					//미방문된 곳만 방문
					if (visited[nextY][nextX] == false) {
						if (map[nextY][nextX] == 'P') {
							meetingPeople++;
						}
						visited[nextY][nextX] = true;
						qsearch.push({ nextX, nextY });
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
		cin >> map[i];
		visited[i] = vector<bool>(col, false);
	}

	int x=0, y=0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'I') {
				x = j;
				y = i;
			}

		}
	}

	bfs(x, y);

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << visited[i][j]<<" ";
		}
		cout << endl;
		
	}*/

	if (meetingPeople != 0) {
		cout << meetingPeople << '\n';
	}
	else {
		cout << "TT\n";
	}

	return 0;
}