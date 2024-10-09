#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    https://please-amend.tistory.com/265
    https://boomrabbit.tistory.com/111

    1. 각 연결요소에 속하는 노드의 개수와 사탕의 총합 구한다
    - DFS/BFS/유니온파인드 사용해서 모든 연결요소 구하기
    - 이때, 각 연결요소에 속하는 노드의 개수와 각 노드에 걸린 사탕의 총합도 구한다

    2. 각 연결요소를 물건으로 생각한다
    (노드 개수=무게, 사탕의 총합=가치)
    - 주어진 한도 k 내에소 최대의 가치(사탕) 얻는 냅색 문제와 같음
    - 노드 개수는 물건 무게
    - 연결요소 내 사탕의 총합은 가치

    3. 배낭의 최대 용량이 k-1인 냅색 문제로 바꾸어 풀이
    - DP를 이용하여 냅색 문제 해결
    
*/

int child, rel, minCry;
vector<vector<int>> adjList;
vector<int> candy;
vector<int> visited;
vector<int> componentSize;
vector<int> componentCandy;
vector<bool> isComponentCalculated;
int totalCandy = 0;

// DFS 함수: 주어진 노드에서 시작하여 연결된 모든 노드를 탐색하며
// 연결 요소의 크기(size)와 사탕의 총합(totalCandy)를 계산
void dfs(int node, int& size, int& totalCandy) {
    visited[node] = 1;  // 현재 노드를 방문했음을 표시
    size++;  // 연결 요소의 크기 증가
    totalCandy += candy[node];  // 사탕의 총합 증가
    
    // 현재 노드와 연결된 다른 노드들에 대해 DFS 호출
    for (int nextNode : adjList[node]) {
        if (!visited[nextNode]) {
            dfs(nextNode, size, totalCandy);
        }
    }
}

int main() {
    cin >> child >> rel >> minCry;

    candy.resize(child + 1);
    adjList.resize(child + 1);
    visited.assign(child + 1, 0);
    isComponentCalculated.assign(child + 1, false);

    // 각 아이가 받은 사탕의 수 입력
    for (int i = 1; i <= child; i++) {
        cin >> candy[i];
    }

    // 아이들의 친구 관계 입력
    for (int i = 0; i < rel; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    // 모든 아이들에 대해 DFS를 수행하여 각 연결 요소의 크기와 사탕의 총합을 계산
    for (int i = 1; i <= child; i++) {
        if (!visited[i]) {
            int size = 0;
            int totalComponentCandy = 0;
            dfs(i, size, totalComponentCandy);
            componentSize.push_back(size);  // 연결 요소의 크기 저장
            componentCandy.push_back(totalComponentCandy);  // 사탕의 총합 저장
        }
    }

    // 냅색 문제를 해결하기 위한 DP 배열 초기화
    vector<int> dp(minCry, 0);

    // 각 연결 요소에 대해 DP 배열을 업데이트하여 최대 사탕의 양 계산
    for (int i = 0; i < componentSize.size(); i++) {
        for (int j = minCry - 1; j >= componentSize[i]; j--) {
            dp[j] = max(dp[j], dp[j - componentSize[i]] + componentCandy[i]);
        }
    }

    // DP 배열의 마지막 값이 스브러스가 어른들에게 들키지 않고 최대한으로
    // 빼앗을 수 있는 사탕의 양
    cout << dp[minCry - 1] << endl;

    return 0;
}
