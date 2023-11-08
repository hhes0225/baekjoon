#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
	boj10026
	적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

	크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
	그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
	또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
	(색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

	예를 들어, 그림이 아래와 같은 경우에

	RRRBB
	GGBBB
	BBBRR
	BBRRR
	RRRRR
	적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 
	하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

	그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.
*/

int mapSize;
vector<string> map;
vector<vector<int>> visited;
vector<vector<int>> colorWeakVisited;

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

int normal = 0;
int colorWeak = 0;

void bfsNormal(int x, int y) {
	normal++;
	visited[y][x]=normal;

	//큐 설정
	queue<pair<int, int>> qsearch;
	qsearch.push({ x, y });

	while (!qsearch.empty()) {
		//큐에서 제거
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//맵 범위 이내여야 함
			if ((nextX >= 0 && nextX < mapSize) && (nextY >= 0 && nextY < mapSize)) {

				//같은 색상일때만 이동해야 함
				if(map[nextY][nextX]==map[here.second][here.first]){

					//방문하지 않았을 때만 방문해야 함
					if (visited[nextY][nextX]==0) {
						visited[nextY][nextX] = visited[here.second][here.first];
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}
}

void bfsColorWeak(int x, int y) {
	//방문처리
	colorWeak++;
	colorWeakVisited[y][x] = colorWeak;

	//큐 생성, enqueue
	queue < pair<int, int>> qsearch;
	qsearch.push({ x, y });

	while (!qsearch.empty()) {
		//dequeue
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//범위 내인지 확인
			if ((nextX >= 0 && nextX < mapSize) && (nextY >= 0 && nextY < mapSize)) {
				//적록색약!!!!
				if ((map[here.second][here.first] == map[nextY][nextX]) ||//R, R / G, G의 경우
					(map[here.second][here.first] == 'R' && map[nextY][nextX] == 'G') ||
					(map[here.second][here.first] == 'G' && map[nextY][nextX] == 'R')) {
					//미방문 상태일때만
					if (colorWeakVisited[nextY][nextX] == 0) {
						colorWeakVisited[nextY][nextX] = colorWeak;
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}
}


int main(void) {
	cin >> mapSize;

	map.resize(mapSize);
	visited.resize(mapSize);
	colorWeakVisited.resize(mapSize);

	for (int i = 0; i < mapSize; i++) {
		cin >> map[i];
		visited[i] = vector<int>(mapSize, 0);
		colorWeakVisited[i] = vector<int>(mapSize, 0);
	}

	//일반인이 보는 이미지
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (visited[i][j] == 0) {
				bfsNormal(j, i);
			}
			else {
				continue;
			}
		}
	}

	//적록색약이 보는 이미지
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (colorWeakVisited[i][j] == 0) {
				bfsColorWeak(j, i);
			}
			else {
				continue;
			}
		}
	}

	cout << normal <<" "<<colorWeak<<'\n';

	return 0;
}