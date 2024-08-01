#include<iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;
#define PII pair<int, int>
//(노드, 거리)

/*
# 다익스트라 알고리즘
- 그래프 한 정점에서 다른 모든 정점까지의 최단경로 찾는 알고리즘
- 가중치 있는 그래프에서 사용되며, 음수 가중치 허용 X

# 우선순위 큐로 구현
- 가장 높은 우선순위를 가진 요소부터 먼저 꺼내짐
- 다익스트라에서는 Min-heap 사용하여 가장 작은 거리 가진 정점 꺼냄
- 힙: 완전 이진 트리 형태, 부모 노드가 자식 노드보다 항상 작거나 큼
- Min-heap: 부모 노드가 자식 노드보다 항상 작은 값
*/

int n, m;
int from, to, weight;
int src, dest;

vector<vector<PII>> adjList;
vector<int> visited;

void dijkstra(int src){
    visited[src]=0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    //최소 힙 구조
    //시작 노드부터 가장 가까운 노드
    
    pq.push({src, 0});

    while(!pq.empty()){
        //큐에서 가장 작은 거리 가진 정점 꺼내고 인접 정점 탐색하며 거리 업데이트        
        int curNode = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if(visited[curNode]<distance){
            continue;
        }

        /*if(curNode==dest){
            cout<<distance<<"\n";
            return;
        }*/

        for(int i=0;i<adjList[curNode].size();i++){
            //선택 노드의 인접노드
            int next = adjList[curNode][i].first;

            //인접노드까지 도달했을 때 소모되는 가중치 비용
            int nextDistance = distance+adjList[curNode][i].second;

            //기존 최소 비용보다 저렴하면 교체
            if(nextDistance<visited[next]){
                visited[next]=nextDistance;
                pq.push({next, nextDistance});
            }
        }
    }

}

int main(void){
    cin>>n>>m;
    
    adjList.resize(n+1);
    visited = vector<int>(n+1, INT_MAX);
    //디폴트값은 무한대
    
    for(int i=0;i<m;i++){
        cin>>from>>to>>weight;

        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    }

    cin>>src>>dest;
    
    dijkstra(src);

    cout<<visited[dest]<<"\n";
    
    return 0;
}

// 이론 참고
// https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
