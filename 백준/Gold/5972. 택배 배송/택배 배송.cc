#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<vector<PII>> adjList;
vector<int> minDist;

void dijkstra(int startNode){
    minDist[startNode]=0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0,startNode});

    while(!pq.empty()){
        auto [curWeight, curNode]=pq.top();
        pq.pop();

        if(curWeight>minDist[curNode]){
            continue;
        }

        for(auto [nextWeight, nextNode]:adjList[curNode]){
            if(minDist[nextNode]>minDist[curNode]+nextWeight){
                minDist[nextNode]=minDist[curNode]+nextWeight;
                pq.push({minDist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    //1-base
    adjList.resize(n+1);
    minDist.assign(n+1, INT_MAX);

    for(int i=0;i<m;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    dijkstra(1);//1-base(현서 위치)

    cout<<minDist.back()<<"\n";
    
    return 0;
}