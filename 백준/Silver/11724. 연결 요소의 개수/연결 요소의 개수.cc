#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*전역변수 선언 영역*/
vector<vector<int>> graph;//노드, 엣지(관계) 연결
vector<bool> visited;//노드 순회 여부 확인

int n, m;//노드, 엣지 개수
int u, v;//시작노드, 끝노드

/*dfs 함수 영역*/
void dfs(int node) {
	visited[node] = true;//해당 노드 방문 처리

	//해당 노드의 자식 노드 순회
	for (int i = 0; i < graph[node].size(); i++) {
		//다음 순회할 노드 설정
		int next = graph[node][i];

		if (visited[next] == false) {//다음 순회 노드를 확인할 것! 현대 인덱스가 아니라!
			dfs(next);//함수 호출도 다음 순회 노드로!!
		}
	}
}


/*main 영역*/
int main(void) {
	cin >> n >> m;

	//입력받은 노드+1만큼 그래프 크기 재설정, 순회 배열도 초기화
	graph.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	//엣지 수만큼 관계를 입력
	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		//관계 입력
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int tree = 0;

	for (int i = 1; i < visited.size(); i++) {

		if (visited[i] == false) {
			//cout << i << " 통과!" << endl;
			dfs(i);
			tree++;
		}
		else {
			continue;
		}
	}

	cout << tree << '\n';


	return 0;
}