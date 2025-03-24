#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<vector<PII>> adjList;
vector<int> mst;
vector<bool> visited;

void getMinCost(int n){
    fill(mst.begin(), mst.end(), INT_MAX);
    fill(visited.begin(), visited.end(), false);
    
    mst[n]=0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0,n});

    while(!pq.empty()){
        auto [curWeight, curNode]=pq.top();
        pq.pop();

        if(visited[curNode]) continue;
        visited[curNode]=true;

        for(auto node:adjList[curNode]){
            auto [nextWeight, nextNode]=node;

            if(!visited[nextNode] && mst[nextNode]>nextWeight){
                //cout<< curNode<<"와"<<nextNode<<"연결\n";
                mst[nextNode]=nextWeight;
                pq.push({nextWeight, nextNode});
            }
        }
    }

    // for(auto it:mst){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
}

int main() {
    int n, m;
    cin>>n>>m;

    adjList.resize(n+1);
    mst.assign(n+1, INT_MAX);
    visited.assign(n+1, false);

    for(int i=0;i<m;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    getMinCost(1);

    int minCost=0;
    for(int i=1;i<=n;i++){
        minCost+=mst[i];
    }
    
    cout<<minCost<<"\n";

    
    return 0;
}