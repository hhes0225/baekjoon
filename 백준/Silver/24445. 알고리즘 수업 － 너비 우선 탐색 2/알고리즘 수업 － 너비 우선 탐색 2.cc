#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
	오늘도 서준이는 너비 우선 탐색(BFS) 수업 조교를 하고 있다. 
	아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

	N개의 정점과 M개의 간선으로 구성된 무방향 그래프(undirected graph)가 주어진다. 
	정점 번호는 1번부터 N번이고 모든 간선의 가중치는 1이다. 
	정점 R에서 시작하여 너비 우선 탐색으로 노드를 방문할 경우 노드의 방문 순서를 출력하자.

	너비 우선 탐색 의사 코드는 다음과 같다. 
	인접 정점은 내림차순으로 방문한다.

	bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
		for each v ∈ V - {R}
			visited[v] <- NO;
		visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
		enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
		while (Q ≠ ∅) {
			u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
			for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 내림차순으로 방문한다)
				if (visited[v] = NO) then {
					visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
					enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
				}
		}
	}
*/

int vertexNum, edgeNum, startNode;
int from, to;
int order = 1;

vector<vector<int>> adjacencyList;
vector<int> visited;

void bfs(int node) {
	queue<int> qsearch;

	//initialization(첫 노드 push)
	visited[node] = order++;
	qsearch.push(node);

	while (qsearch.empty() == false) {//== !qsearch.empty()
		//큐에서 제거
		int here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < adjacencyList[here].size(); i++) {
			int next = adjacencyList[here][i];


			//방문하지 않았다면
			if (visited[next] == 0) {
				//방문 처리 & 큐에 삽입
				visited[next] = order++;
				qsearch.push(next);
			}
		}
	}

	return;
}

int main(void) {
	cin >> vertexNum >> edgeNum >> startNode;

	//버텍스 개수 정보 사용
	adjacencyList.resize(vertexNum + 1);
	visited = vector<int>(vertexNum + 1, 0);


	//엣지 개수 정보 사용
	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;
		
		//undirected graph이므로 양방향으로 push_back
		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);
	}

	//기본 오름차순이지만 문제 조건에서 내림차순 정렬하라고 했으므로 내림차순
	for (int i = 1; i < adjacencyList.size(); i++) {
		sort(adjacencyList[i].begin(), adjacencyList[i].end());
		reverse(adjacencyList[i].begin(), adjacencyList[i].end());
	}

	//startNode 정보 이용
	bfs(startNode);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << "\n";
	}


	return 0;
}
