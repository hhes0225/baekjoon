#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*전역변수 선언*/
int n, m, r;//노드, 엣지, 시작노드

vector<vector<int>> graph;
vector<int> visited;//해당 노드가 몇번째에 방문되었는지 출력하기 위해 int로 설정
int order = 0;// 방문 순서를 visited로 저장

int u, v;//노드 간선 이을때 사용

void dfs(int node) {
	//해당 노드 방문 처리
	order++;
	visited[node] = order;

	//노드의 자식 노드들 순회
	for (int i = 0; i < graph[node].size(); i++) {
		//바로 순회해야 할 다음 노드 설정
		int next = graph[node][i];

		//해당 노드가 방문하지 않은 노드라면 방문
		//그렇지 않고 이미 방문했다면 pass하기
		if (visited[next] == false) {
			dfs(next);
		}
	}
}

int main(void) {
	//n, m, r 입력받기
	cin >> n >> m >> r;

	//그래프 리사이즈(노드개수+1)
	graph.resize(n + 1);

	//노드와 엣지 연결
	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//방문 벡터 사이즈 설정, 0으로 초기화
	visited = vector<int>(n + 1, 0);

	//오름차순으로 방문하기 위해 정렬
	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//함수 호출(그래프 순회 시작 노드와 함께, 이 경우는 r=1이므로 1)
	dfs(r);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}