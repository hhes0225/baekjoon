#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
	boj11060

	재환이가 1×N 크기의 미로에 갇혀있다. 미로는 1×1 크기의 칸으로 이루어져 있고, 각 칸에는 정수가 하나 쓰여 있다. 
	i번째 칸에 쓰여 있는 수를 Ai라고 했을 때, 재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 한 번에 점프할 수 있다. 
	예를 들어, 3번째 칸에 쓰여 있는 수가 3이면, 재환이는 4, 5, 6번 칸 중 하나로 점프할 수 있다.

	재환이는 지금 미로의 가장 왼쪽 끝에 있고, 가장 오른쪽 끝으로 가려고 한다. 
	이때, 최소 몇 번 점프를 해야 갈 수 있는지 구하는 프로그램을 작성하시오. 
	만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.
*/

vector<vector<int>> adjList;
vector<int> visited;

int vertices;

int jump = 0;

void bfs() {
	//첫 노드 방문 처리
	visited[0] = jump++;

	//큐 생성, enqueue
	queue<int> qsearch;
	qsearch.push(0);

	while (!qsearch.empty()) {
		//dequeue
		int here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < adjList[here].size(); i++) {
			int next = adjList[here][i];
			
			//범위 이내라면
			if (next < vertices) {
				//미방문 상태라면
				if(visited[next] == -1){
					//방문처리 / enqueue / 점프횟수 + 1
					visited[next] = visited[here] + 1;
					qsearch.push(next);
				}
			}
		}
	}

}


int main(void) {
	cin >> vertices;

	int step;

	adjList.resize(vertices);
	visited = vector<int>(vertices, -1);

	for (int i = 0; i < vertices; i++) {
		cin >> step;

		for (int j = 0; j < step; j++) {
			adjList[i].push_back(i + j+1);
		}

		sort(adjList[i].begin(), adjList[i].end());
	}

	/*for (int i = 0; i < vertices; i++) {

		for (int j = 0; j < adjList[i].size(); j++) {
			cout << adjList[i][j] << " ";

		}

		cout << endl;
	}*/

	bfs();

	/*for (int i = 0; i < visited.size(); i++) {
		cout << visited[i] << endl;
	}*/

	cout << visited[visited.size() - 1] << '\n';
	// 갈 수 없는 경우 체크하지 않아도 됨 - 어차피 -1로 초기화했기 때문에 
	// 분기 체크하고 갈 수 없으면 어차피 값이 -1임. 그래서 -1 출력을 굳이 안해도 됨


	return 0;
}