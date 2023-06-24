#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*전역 변수 영역*/
vector<vector<int>> graph;
vector<int> visited;

int n;//노드 개수, n-1이 엣지 개수
int s, e;//시작 노드-끝 노드


/*dfs 함수 영역*/
void dfs(int node, int parent) {
	visited[node] = parent;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (visited[next] == false) {
			dfs(next, node);
		}
	}
}

/*main 영역*/
int main(void) {
	cin >> n;

	graph.resize(n + 1);
	visited = vector<int>(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(1, 0);

	for (int i = 2; i < graph.size(); i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}
