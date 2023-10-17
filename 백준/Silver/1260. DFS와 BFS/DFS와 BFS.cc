#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
*	boj1260
	그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
	단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
	더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
	정점 번호는 1번부터 N번까지이다.
*/

int vertexNum, edgeNum, startNode;

vector<vector<int>> adjcencyList;
vector<bool> visited;

int from, to;

void dfs(int node) {
	//노드 방문처리(재귀함수라서 첫번째든 아니든 상관없이 방문처리)
	visited[node] = true;
	cout << node << " ";

	for (int i = 0; i < adjcencyList[node].size(); i++) {
		//다음 탐색할 노드 설정
		int next = adjcencyList[node][i];

		//다음 탐색할 노드가 방문 안한 노드면 방문
		if (visited[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int node) {
	queue<int> qsearch;

	//첫번째 노드 방문처리
	visited[node] = true;
	qsearch.push(node);

	while (!qsearch.empty()) {
		//큐에서 꺼내는 작업(frontpop)
		int here = qsearch.front();
		qsearch.pop();
		cout << here << " ";

		for (int i = 0; i < adjcencyList[here].size(); i++) {
			int next = adjcencyList[here][i];

			//방문 아직 안했을 경우 방문처리
			if (visited[next] == false) {
				visited[next] = true;
				qsearch.push(next);
			}
		}
		
	}
}

int main(void) {
	cin >> vertexNum >> edgeNum >> startNode;

	//vertexNum 정보 사용
	adjcencyList.resize(vertexNum + 1);
	visited = vector<bool>(vertexNum + 1, false);

	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;

		adjcencyList[from].push_back(to);
		adjcencyList[to].push_back(from);
	}

	for (int i = 1; i < adjcencyList.size(); i++) {
		sort(adjcencyList[i].begin(), adjcencyList[i].end());
	}

	dfs(startNode);

	cout << '\n';
	visited = vector<bool>(vertexNum + 1, false);

	bfs(startNode);

	return 0;
}