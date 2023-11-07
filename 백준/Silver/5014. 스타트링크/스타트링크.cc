#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
	boj 5014
	강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다. 
	오늘은 강호의 면접날이다. 하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.

	스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 
	강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

	보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다.
	U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. 
	(만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

	강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 
	만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.


	***
	
	unweighted directed graph
	"최소, 최단경로" -> BFS
*/

int F, S, G, U, D;

vector<vector<int>> adjList;
vector<int> visited;

void bfs(int startNode) {
	//첫노드 방문처리
	visited[startNode]++;

	//큐 생성, enqueue
	queue<int> qsearch;
	qsearch.push(startNode);

	while (!qsearch.empty()) {
		//큐에 있는 것 꺼내서 삭제 dequeue
		int here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < adjList[here].size(); i++) {
			int next = adjList[here][i];

			//방문 안했으면
			if (visited[next] == -1) {
				//방문처리
				visited[next] = visited[here] + 1;
				//큐에 삽입
				qsearch.push(next);
			}
		}
	}
}

int main(void) {
	cin >> F >> S >> G >> U >> D;

	adjList.resize(F+1);
	visited = vector<int>(F + 1, -1);

	for (int i = 1; i < F + 1; i++) {
		if (i - D >= 1)
			adjList[i].push_back(i - D);
		if (i + U <= F)
			adjList[i].push_back(i + U);
	}


	/*for (int i = 1; i < F + 1; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjList[i].size(); j++) {
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}*/

	bfs(S);

	/*for (int i = 1; i < F + 1; i++) {
		cout << visited[i] << endl;
	}*/

	if (visited[G] != -1) {
		cout << visited[G]<<"\n";
	}
	else {
		cout << "use the stairs\n";
	}

	return 0;
}