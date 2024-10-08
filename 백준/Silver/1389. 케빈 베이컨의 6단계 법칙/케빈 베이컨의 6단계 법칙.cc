#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
	boj1389
	케빈 베이컨의 6단계 법칙에 의하면 지구에 있는 모든 사람들은 최대 6단계 이내에서 서로 아는 사람으로 연결될 수 있다. 
	케빈 베이컨 게임은 임의의 두 사람이 최소 몇 단계 만에 이어질 수 있는지 계산하는 게임이다.

	예를 들면, 전혀 상관없을 것 같은 인하대학교의 이강호와 서강대학교의 민세희는 몇 단계만에 이어질 수 있을까?

	천민호는 이강호와 같은 학교에 다니는 사이이다. 
	천민호와 최백준은 Baekjoon Online Judge를 통해 알게 되었다. 
	최백준과 김선영은 같이 Startlink를 창업했다. 
	김선영과 김도현은 같은 학교 동아리 소속이다. 
	김도현과 민세희는 같은 학교에 다니는 사이로 서로 알고 있다. 
	즉, 이강호-천민호-최백준-김선영-김도현-민세희 와 같이 5단계만 거치면 된다.

	케빈 베이컨은 미국 헐리우드 영화배우들 끼리 케빈 베이컨 게임을 했을때 나오는 단계의 총 합이 가장 적은 사람이라고 한다.

	오늘은 Baekjoon Online Judge의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 찾으려고 한다. 
	케빈 베이컨 수는 모든 사람과 케빈 베이컨 게임을 했을 때, 나오는 단계의 합이다.


	예를 들어, BOJ의 유저가 5명이고, 1과 3, 1과 4, 2와 3, 3과 4, 4와 5가 친구인 경우를 생각해보자.

	1은 2까지 3을 통해 2단계 만에, 3까지 1단계, 4까지 1단계, 5까지 4를 통해서 2단계 만에 알 수 있다. 
	따라서, 케빈 베이컨의 수는 2+1+1+2 = 6이다.

	2는 1까지 3을 통해서 2단계 만에, 3까지 1단계 만에, 4까지 3을 통해서 2단계 만에, 5까지 3과 4를 통해서 3단계 만에 알 수 있다. 
	따라서, 케빈 베이컨의 수는 2+1+2+3 = 8이다.

	3은 1까지 1단계, 2까지 1단계, 4까지 1단계, 5까지 4를 통해 2단계 만에 알 수 있다. 
	따라서, 케빈 베이컨의 수는 1+1+1+2 = 5이다.

	4는 1까지 1단계, 2까지 3을 통해 2단계, 3까지 1단계, 5까지 1단계 만에 알 수 있다. 
	4의 케빈 베이컨의 수는 1+2+1+1 = 5가 된다.

	마지막으로 5는 1까지 4를 통해 2단계, 2까지 4와 3을 통해 3단계, 3까지 4를 통해 2단계, 4까지 1단계 만에 알 수 있다. 
	5의 케빈 베이컨의 수는 2+3+2+1 = 8이다.

	5명의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람은 3과 4이다.

	BOJ 유저의 수와 친구 관계가 입력으로 주어졌을 때, 케빈 베이컨의 수가 가장 작은 사람을 구하는 프로그램을 작성하시오.

	----------------
	바보인가??? 가장 작은 케빈 베이컨 수 구하는게 아니라
	최소 케빈 베이컨 수를 가진 ""사람""을 구하는 거라고!!!!!!
	입출력 테스트케이스 틀렸다고 혼냈는데 챗지피티야 미안해...
*/

int vertexNum, edgeNum;

vector<vector<int>> adjList;
vector<int> visited;

int from, to;


void bfs(int node) {
	queue<int> qsearch;

	//첫번째 노드 방문처리
	visited[node] = 0;
	qsearch.push(node);

	while (!qsearch.empty()) {
		//큐 frontpop 처리
		int here = qsearch.front();
		qsearch.pop();

		//cout << "bfs node: " << here << '\n';

		for (int i = 0; i < adjList[here].size(); i++) {
			int next = adjList[here][i];

			if (visited[next] == -1) {
				visited[next] = visited[here] + 1;//부모 노드 값 + 1, 계층별로 같은 값을 공유하게 됨
				qsearch.push(next);
			}
		}
	}

}

int main(void) {
	int baconNum=0;
	int minBacon = 9999;
	int minBaconPerson = 0;

	cin >> vertexNum >> edgeNum;

	//vertexNum 정보 사용
	adjList.resize(vertexNum + 1);
	visited = vector<int>(vertexNum + 1, -1);

	//edgeNum 정보 사용
	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;

		//중복제거
		if (find(adjList[from].begin(), adjList[from].end(), to) != adjList[from].end()) {//값이 이미 있으면
			continue;
		}
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}


	for (int i = 1; i < adjList.size(); i++) {
		sort(adjList[i].begin(), adjList[i].end());
	}

	for (int i = 1; i < adjList.size(); i++) {
		bfs(i);

		//cout << i << "번째: " << '\n';
		
		//케빈 베이컨 수 총합 구하기
		for (int j = 1; j < visited.size(); j++) {
			//cout << visited[j]<<'\n';
			if(visited[j] != -1)
				baconNum += visited[j];
		}

		if (baconNum < minBacon) {
			minBacon = baconNum;
			minBaconPerson = i;
		}

		

		//다음 넘어가기 전 초기화
		visited = vector<int>(vertexNum + 1, -1);
		baconNum = 0;
	}

	cout << minBaconPerson << '\n';
	return 0;
}