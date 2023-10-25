#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	boj7576
	철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다.
	토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

	창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
	보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
	하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
	대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
	철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

	토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때,
	며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.
	단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

vector<vector<int>> tomatoBox;
vector<vector<int>> visited;

int row, col;

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<int, int>> qsearch;

	//토마토가 있는 부분(tomatoBox 값이 1) 큐에 다 넣어놓기
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (tomatoBox[i][j] == 1) {
				//방문처리 및 큐에 삽입
				visited[i][j]++;
				qsearch.push({ j, i });//배열에서 x와 y 값은 반대 순서
			}
			else if (tomatoBox[i][j] == -1) {
				visited[i][j]--;
				//없는 칸은 -로 초기화
			}
		}
	}

	//이를 기반으로 bfs
	while (!qsearch.empty()) {

		//큐에서 제거(dequeue, frontpop)
		pair<int, int> here = qsearch.front();
		//cout << here.first << here.second << '\n';
		qsearch.pop();		

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//배열 범위 이내라면
			if ((nextX >= 0 && nextX < col) && (nextY >= 0 && nextY < row)) {
				//토마토가 있으면서 토마토가 익지 않은 칸 체크 = 0인 칸
				//(즉, 1: 토마토 익은 칸, -1:토마토 없는 칸이 아닌 칸)
				if (tomatoBox[nextY][nextX] == 0) {
					//방문하지 않은 칸
					if (visited[nextY][nextX] == -1) {
						//방문 처리
						visited[nextY][nextX] = visited[here.second][here.first] + 1;//여기서 왜 == 쓰냐고? 할당연산자 =를 써야지...
						//큐에 삽입
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> col >> row;

	tomatoBox.resize(row);
	visited.resize(row);

	for (int i = 0; i < row; i++) {
		visited[i] = vector<int>(col, -1);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int tmp;
			cin >> tmp;
			tomatoBox[i].push_back(tmp);
		}
	}

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << tomatoBox[i][j] << " ";
		}
		cout << '\n';
	}*/

	bfs();

	int minDay = -1;
	bool allTomato = true;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == -1) {
				allTomato = false;
				break;
			}
			minDay = max(minDay, visited[i][j]);//여기서 j i라고 하니까 인덱스 에러가 뜨지
		}
	}

	if (allTomato)
		cout << minDay << '\n';
	else
		cout << -1 << "\n";

	return 0;
}