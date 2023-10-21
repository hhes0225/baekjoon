#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	boj2667
	<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
	철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
	여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
	대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
	지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

 	처음에는 DFS로만 풀었지만 연습삼아 BFS로도 풂
*/

vector<vector<int>> map;
vector<vector<bool>> visited;

int mapSize;

//상하좌우로만 이동 조합
int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };

//단지 번호(main dfs 이후 초기화할 것)
int complexNum = 1;

void bfs(int x, int y) {
	//첫 노드 방문 처리
	visited[y][x] = true;

	//큐 생성 및 첫 노드 push
	queue<pair<int, int>> qsearch;
	qsearch.push({ x, y });

	while (!qsearch.empty()) {
		//큐에서 dequeue(front pop)
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + moveX[i];
			int nextY = here.second + moveY[i];

			//배열 인덱스 내부 범위인지 확인
			if ((nextX >= 0 && nextX < mapSize) && (nextY >= 0 && nextY < mapSize)) {
				//아파트 단지 있는지 확인
				if (map[nextY][nextX] == 1) {
					//방문 여부 확인-방문 안했으면 방문 처리 후 큐에 삽입+단지 개수 1씩 누적
					if (visited[nextY][nextX] == false) {
						visited[nextY][nextX] = true;
						qsearch.push({ nextX, nextY });
						complexNum++;
					}
				}
			}
		}

	}
}

void dfs(int x, int y) {
	//dfs는 우선 방문처리
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		//다음 탐색할 상하좌우 이동 시 좌표 설정
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];

		//다음 탐색할 좌표가 맵 범위에서 벗어나는지 확인
		if ((nextX >= 0 && nextX < mapSize) && (nextY >= 0 && nextY < mapSize)) {
			//아파트가 있는 곳만 탐색
			if (map[nextY][nextX] == 1) {
				//탐색 안한곳만 순회(이미 탐색한 곳 말고)
				if (visited[nextY][nextX] == false) {
					complexNum++;//연결된 아파트 개수만큼 설정
					dfs(nextX, nextY);//dfs는 재귀함수로
				}
			}
		}
	}

}



int main(void) {
	vector<int> apartment;

	cin >> mapSize;
	string input;

	map.resize(mapSize);
	visited.resize(mapSize);

	for (int i = 0; i < mapSize; i++) {
		//map[i] = vector<int>(mapSize, 0);
		visited[i] = vector<bool>(mapSize, false);
	}

	for (int i = 0; i < mapSize; i++) {
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			map[i].push_back((int)input[j] - (int)'0');
		}
	}

	/*for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				bfs(j, i);// 배열에서 x와 y는 반대
				//dfs(j, i);// 배열에서 x와 y는 반대
				apartment.push_back(complexNum);
				complexNum = 1;//단지 번호 초기화
			}
		}
	}

	sort(apartment.begin(), apartment.end());

	cout << apartment.size() << '\n';
	for (int i = 0; i < apartment.size(); i++) {
		cout << apartment[i] << '\n';
	}

	return 0;
}
