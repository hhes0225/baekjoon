#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
# define REALLIMIT 100000
# define LIMIT 200001

/*
	boj1697
	수빈이는 동생과 숨바꼭질을 하고 있다. 
	수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
	수빈이는 걷거나 순간이동을 할 수 있다. 
	만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
	순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

	수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/

/*
	***** 틀린 이유
	큰 수 -> 작은 수일 경우
	가능한 경우의 수는 단 한가지, -1씩 해서 작은 수로 도달하기이다(나누기 2는 존재하지 않는다)
	따라서 가능한 next범위를 here-1부터로 한정한다.(here - 1보다, 즉 minus 1보다 작다면 그냥 순회하지 마라, 다른 노드의 multiple 2이다)
*/

vector<vector<int>> adjList;
vector<int> visited;

int startNode, endNode;

void bfs(int startNode) {
	//시작 노드 방문처리
	visited[startNode]++;

	//큐에 삽입
	queue<int> qsearch;
	qsearch.push(startNode);

	while (!qsearch.empty()) {
		//큐에서 dequeue(frontpop)
		int here = qsearch.front();
		qsearch.pop();

		//cout << here << "\n";

		for (int i = 0; i < adjList[here].size(); i++) {
			int next = adjList[here][i];

			//방문 여부 확인
			if (visited[next] == -1 && (here - 1 <= next)) {
				//방문 처리
				visited[next] = visited[here] + 1;
				qsearch.push(next);
			}
		}
	}


}

int main(void) {
	cin >> startNode >> endNode;

	adjList.resize(LIMIT);
	visited = vector<int>(LIMIT, -1);

	//x-1, x+1, x*2의 자식을 가지는 그래프 생성(중복 제거)
	for (int i = 0; i < REALLIMIT; i++) {
		int minus1 = i - 1;
		int plus1 = i + 1;
		int multiple2 = i * 2;

		if (minus1 < 0) {
			continue;
		}

		if (find(adjList[i].begin(), adjList[i].end(), minus1) == adjList[i].end()) {//없는 값이라면 삽입
			adjList[i].push_back(minus1);
			adjList[minus1].push_back(i);
		}
		if (find(adjList[i].begin(), adjList[i].end(), plus1) == adjList[i].end()) {//없는 값이라면 삽입
			adjList[i].push_back(plus1);
			adjList[plus1].push_back(i);
		}
		if (find(adjList[i].begin(), adjList[i].end(), multiple2) == adjList[i].end()) {//없는 값이라면 삽입
			adjList[i].push_back(multiple2);
			adjList[multiple2].push_back(i);
		}

		sort(adjList[i].begin(), adjList[i].end());
	}

	////그래프 잘 삽입되었는지 테스트 출력
	//for (int i = 0; i < adjList.size(); i++) {
	//	cout << i << " ";
	//	for (int j = 0; j < adjList[i].size(); j++) {
	//		cout << adjList[i][j] << " ";
	//	}

	//	cout << "\n";
	//}


	//cout << "before BFS\n";

	bfs(startNode);

	//cout << "after BFS\n";

	cout << visited[endNode]<<'\n';

	return 0;
}