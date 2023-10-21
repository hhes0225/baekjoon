#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	boj1012
	차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 
	농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 
	한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 

	이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
	특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 
	그 배추들 역시 해충으로부터 보호받을 수 있다. 
	한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.

	한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 
	배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 
	서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다. 
	예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다. 
	0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.

	1	1	0	0	0	0	0	0	0	0
	0	1	0	0	0	0	0	0	0	0
	0	0	0	0	1	0	0	0	0	0
	0	0	0	0	1	0	0	0	0	0
	0	0	1	1	0	0	0	1	1	1
	0	0	0	0	1	0	0	1	1	1

 	처음에는 DFS로 풀었으나 연습용으로 BFS로도 풀었음!
*/

vector<vector<int>> farm;
vector<vector<bool>> visited;

//상, 하, 좌, 우로만 이동할 수 있도록 하기 위함
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int cater = 0;

void bfs(int i, int j) {
	// 첫 노드 방문 처리
	visited[j][i] = true;

	//큐에 삽입, 큐도 visited와 마찬가지로 2차원 큐여야 함
	queue<pair<int, int>> qsearch;
	qsearch.push({ i, j });//그러네 입력 줄때는 무조건 i는 x고 j 는 y니까 이대로 push해도 되는구나

	while (!qsearch.empty()) {
		//큐에서 삭제
		pair<int, int> here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = here.first + dx[i];
			int nextY = here.second + dy[i];

			//새로운 이동한 인덱스가 배열 범위 이내인지 확인
			if ((nextX >= 0 && nextX < farm[0].size()) && (nextY >= 0 && nextY < farm.size())) {
				//배추가 있는지 확인
				if (farm[nextY][nextX] == 1) {
					//방문했는지 확인
					if (visited[nextY][nextX] == false) {
						//dfs-재귀함수 / bfs - 큐에 삽입
						//방문처리
						visited[nextY][nextX] = true;
						qsearch.push({ nextX, nextY });
					}
				}
			}
		}
	}
}

void dfs(int i, int j) {
	//들어온 것 방문처리
	visited[j][i]=true;//배열은 x y가 아니라 y x순이므로

	for (int t = 0; t < 4; t++) {
		int nextX = i + dx[t];
		int nextY = j + dy[t];

		//nextX와 nextY의 인덱스가 farm의 인덱스를 넘지 않도록 함
		if ((nextX >= 0 && nextX <farm[0].size())&&(nextY >= 0 && nextY < farm.size())) {
			if (farm[nextY][nextX]==1) {//배추 없으면 굳이 방문 안하기
				if (visited[nextY][nextX]==false) {//방문 안했으면 dfs 호출, 방문처리
					//cout << "i: " << i << " j: " << j << '\n';
					dfs(nextX, nextY);
				}
			}
		}
	}

}

int main(void) {
	int tCase;
	int row, col;
	int numCabbage;

	cin >> tCase;

	for (int t = 0; t < tCase; t++) {
		cin >> col >> row >> numCabbage;

		farm.resize(row);
		visited.resize(row);

		for (int i = 0; i < row; i++) {
			farm[i] = vector<int>(col, 0);
			visited[i] = vector<bool>(col, false);
		}

		for (int i = 0; i < numCabbage; i++) {
			int x, y;
			cin >> x >> y;
			farm[y][x]++;//배열은 x y가 아니라 y x순이므로
		}

		/*for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << farm[i][j] << " ";
			}
			cout << "\n";
		}*/

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if(visited[i][j]==false && farm[i][j] == 1){
					cater++;
					bfs(j, i);//배열은 x y가 아니라 y x순이므로
					//dfs(j, i);
				}
			}
		}

		cout << cater << '\n';
		cater = 0;
		farm.clear();
		visited.clear();
	}
	

	return 0;
}
