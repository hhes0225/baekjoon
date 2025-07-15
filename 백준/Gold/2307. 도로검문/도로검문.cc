#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<vector<PII>> adjList;

vector<int> prevNode;
vector<PII> minRoute;

int dijkstra_1st(int node, int size){
    vector<int> visited(size, INT_MAX);
    visited[node]=0;
    prevNode.push_back(node);
    
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0,node});

    while(!pq.empty()){
        auto [curWeight, curNode]=pq.top();
        pq.pop();

        if(curWeight>visited[curNode]) continue;

        for(auto next:adjList[curNode]){
            auto [nextWeight, nextNode]=next;

            if(curWeight+nextWeight<visited[nextNode]){
                visited[nextNode]=curWeight+nextWeight;
                prevNode[nextNode]=curNode;//이전 노드로 기
                pq.push({curWeight+nextWeight, nextNode});
            }
        }
    }
    

    return visited[size-1]; 
}

void tracePath(int node){
    if(prevNode[node]==0){
        return;
    }

    minRoute.push_back({prevNode[node], node});
    tracePath(prevNode[node]);
}

int dijkstra_2nd(int node, int from, int to, int size){
    vector<int> visited(size, INT_MAX);
    visited[node]=0;
    
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0,node});

    while(!pq.empty()){
        auto [curWeight, curNode]=pq.top();
        pq.pop();

        if(curWeight>visited[curNode]) continue;

        for(auto next:adjList[curNode]){
            auto [nextWeight, nextNode]=next;

            if((from==nextNode && to==curNode)||(from==curNode&&to==nextNode)) continue;

            if(curWeight+nextWeight<visited[nextNode]){
                visited[nextNode]=curWeight+nextWeight;
                pq.push({curWeight+nextWeight, nextNode});
            }
        }
    }

    return visited[size-1];
    
}

int main() {
    int n, e;
    cin>>n>>e;

    adjList.resize(n+1);
    prevNode.resize(n+1);
    // visited.assign(n+1, INT_MAX);

    for(int i=0;i<e;i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    //최초 다익스트라 돌면서 minRoute 추가를 위한 경로 및 비교용 최초 최단거리 체크
    int minDist_1st=dijkstra_1st(1, n+1);
    // cout<<minDist_1st<<"\n";
    // for(auto p:prevNode)cout<<p<<" ";
    // cout<<"\n";

    tracePath(n);//재귀함수로 다익스트라 경로 역추
    // for(auto m:minRoute)cout<<m.first<<" "<<m.second<<"\n";
    // cout<<"\n";

    int increased=0;
    //최소 경로의 구성요소 한 개씩 빼보면서 그때의 최대 지연시간 구하기
    for(auto m:minRoute){
        auto [from, to]=m;
        
        increased=max(increased, dijkstra_2nd(1, from, to, n+1));
        // cout<<increased<<" "<<INT_MAX<<"\n";
        
    }

    if(increased==INT_MAX) cout<<-1<<"\n";
    else cout<<increased-minDist_1st<<"\n";
    
    
    return 0;
}