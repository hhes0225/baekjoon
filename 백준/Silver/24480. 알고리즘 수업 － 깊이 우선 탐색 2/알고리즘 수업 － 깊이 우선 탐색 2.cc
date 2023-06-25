#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*전역 변수 영역*/
vector<vector<int>> graph;
vector<int> visited;

int n, m;//num of node, edge

int init = 1;
int order = 0;

int u, v;//start node, end node

/*dfs 함수 영역*/
void dfs(int node) {
	order++;
	visited[node] = order;


	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (visited[next] == false) {
			dfs(next);
		}
	}
}

/*main 영역*/
int main(void) {
	cin >> n >> m>>init;

	graph.resize(n + 1);
	visited = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
		reverse(graph[i].begin(), graph[i].end());
	}

	dfs(init);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << '\n';
	}


	return 0;
}