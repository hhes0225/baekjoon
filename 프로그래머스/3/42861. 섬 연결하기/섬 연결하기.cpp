#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// 무방향 weighted 그래프
// 최소 비용 -> 최소 신장트리(Minimum Spanning Tree) 로 해결
// 크루스칼 or 프림 알고리즘 적용
// 크루스칼, 프림 알고리즘 설명: https://ansohxxn.github.io/algorithm/mst/
/* 크루스칼
무조건 가장 비용이 작은 간선부터 선택해 나간다는 점에서 Greedy
프림:
프림 또한 Greedy하다. 시작 할 때 시작 정점만 MST 집합에 포함시키고 현재까지의 MST 집합에 포함된 정점들 중에서 인접한 정점들 中 가중치 최소 간선으로 연결된 정점을 선택하여 트리를 확장
*/

vector<vector<int>> weightedGraph;
vector<int> visited;
vector<int> unvisited;

void makeGraph(int n, vector<vector<int>> costs){
    vector<vector<int>> tmp(n, vector<int>(n));
    weightedGraph = tmp;
    
    for(int i=0;i<costs.size();i++){
        int from = costs[i][0];
        int to = costs[i][1];
        weightedGraph[from][to] = costs[i][2];
        weightedGraph[to][from] = costs[i][2];
    }
}



int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //인접 리스트 만들기
    makeGraph(n, costs);
    
    //첫 번째 노드 방문 처리
    visited.push_back(0);
    
    //나머지 노드 미방문 처리
    for(int i=1;i<n;i++){
        unvisited.push_back(i);
    }
    
    for(int i=1;i<n;i++){
        int min = INT_MAX;
        int minIdx = 0;
        
        for(int j=0;j<i;j++){
            for(int k=0;k<n-i;k++){
                if(weightedGraph[visited[j]][unvisited[k]]>0&&min>weightedGraph[visited[j]][unvisited[k]]){
                    min=weightedGraph[visited[j]][unvisited[k]];
                    minIdx=k;
                }
            }
        }
        
        visited.push_back(unvisited[minIdx]);
        unvisited.erase(unvisited.begin()+minIdx);
        answer+=min;
    }
    
    return answer;
}

//참고(접근법)
//https://school.programmers.co.kr/questions/43935