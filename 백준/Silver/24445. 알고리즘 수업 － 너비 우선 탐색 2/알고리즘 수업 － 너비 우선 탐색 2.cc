#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
	boj24444
	오늘도 서준이는 너비 우선 탐색(BFS) 수업 조교를 하고 있다. 
	아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

	N개의 정점과 M개의 간선으로 구성된 무방향 그래프(undirected graph)가 주어진다. 
	정점 번호는 1번부터 N번이고 모든 간선의 가중치는 1이다. 
	정점 R에서 시작하여 너비 우선 탐색으로 노드를 방문할 경우 노드의 방문 순서를 출력하자.

	너비 우선 탐색 의사 코드는 다음과 같다. 
	인접 정점은 오름차순으로 방문한다.

	bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
		for each v ∈ V - {R}
			visited[v] <- NO;
		visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
		enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
		while (Q ≠ ∅) {
			u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
			for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
				if (visited[v] = NO) then {
					visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
					enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
				}
		}
	}
*/

int vertexNum, edgeNum, startVertex;
/*
	vertexNum = 그래프 버텍스의 총 개수
	edgeNum = 그래프 엣지의 총 개수
	startVertex = BFS 함수에 매개변수로 넣을 시작노드 번호
*/

vector<vector<int>> adjList; 
//adjacency list로 어떤 노드가 어떤 노드가 연결되어있는지 확인
vector<int> visited;//노드 방문 여부(color-white, grey, black에서 white랑 black만 따진다)

int from, to;
//노드랑 노드 연결 입력할 때 사용. 
//undirected의 경우엔 from-to 상관없이 양쪽에 각각 연결되었다고 넣어준다


void bfs(int startVertex) {
	queue<int> qsearch; 
	// 인접 연결된 노드 저장해서 순회 순서 결정

	int order = 1;
	visited[startVertex] = order++;
	//bfs 함수에 들어오면, node의 방문 여부 체크

	qsearch.push(startVertex);
	//node의 값을 queue에 push

	while (!qsearch.empty()) {//queue가 전부 빌 때까지
		int here = qsearch.front();
		//cout << here << '\n';
		qsearch.pop();
		//Q.remove() 역할 - frontpop == dequeue

		for (int i = 0; i < adjList[here].size(); i++) {//버텍스 here과 연결된 모든 노드 순회
			int next = adjList[here][i];//버텍스 here과 연결된 노드 값 next로 저장

			if (visited[next] == false) {//next 노드가 방문된 노드가 아니라면
				visited[next] = order++;//방문여부 -> 방문 순서로 처리(방문 순서 0이 아니면 순회완료)
				qsearch.push(next);
				//enqueue == queue에 다음으로 순회할 노드(부모와 가장 가까웠던 노드이므로)로 설정하기 위해 push
			}
		}


	}
}

int main(void) {
	cin >> vertexNum >> edgeNum >> startVertex;

	adjList.resize(vertexNum + 1); 
	// 번호 0부터 시작 안하고 1부터 시작하기 때문

	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;

		//undirected graph
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	visited = vector<int>(vertexNum + 1, 0);
	//white(undiscovered)로 초기화

	//adjacency list는 항상 오름차순으로 정렬
	for (int i = 1; i < adjList.size(); i++) {
		sort(adjList[i].begin(), adjList[i].end());
		reverse(adjList[i].begin(), adjList[i].end());
	}

	bfs(startVertex);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}