#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*전역 변수 선언 영역*/
vector<vector<int>> graph;
vector<bool> visited;

int n, m;//노드, 엣지 개수
int s, e;//시작, 끝 노드

bool finished = false;

int from, to;

int chon = 0;


/*dfs 함수 영역*/
void dfs(int node) {
	visited[node] = true;
	if (node == e){
		//cout << "escape" << endl;
		finished = true;
		return;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (visited[next] == false && !finished) {
			dfs(next);
		}
	}

	if (finished) {
		chon++;
	}
}

/*main 영역*/
int main(void) {
	cin >> n >> s >> e >> m;//노드개수, 시작노드번호, 끝노드번호, 엣지개수 입력받기

	graph.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++) {
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(s);

	if (finished == true)
		cout << chon << '\n';
	else
		cout << -1 << '\n';

	return 0;
}