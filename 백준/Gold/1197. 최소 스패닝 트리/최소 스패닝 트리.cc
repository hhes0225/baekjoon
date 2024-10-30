#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

int n, e;
vector<vector<PII>> adjList;
vector<bool> visited;
vector<int> mst;
/*
void prim(int start){
    mst[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode=pq.top().second;
        int curWeight=pq.top().first;

        pq.pop();

        for(int i=0;i<adjList[curNode].size();i++){
            int nextNode=adjList[curNode][i].second;
            int nextWeight=adjList[curNode][i].first;

						//요부분만 변경!!
            if(mst[curNode]+nextWeight<mst[nextNode]){ 
                mst[nextNode]=min(mst[nextNode], nextWeight);
                pq.push({mst[nextNode], nextNode});
            }
        }
    }
}*/

void prim(int start){
    //visited[]
    mst[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight=pq.top().first;

        pq.pop();

        if(visited[curNode]){
            continue;
        }
        visited[curNode]=true;

        for(auto it:adjList[curNode]){
            int nextNode=it.second;
            int nextWeight=it.first;

            if(!visited[nextNode] && mst[nextNode]>nextWeight){
                mst[nextNode]=nextWeight;
                pq.push({nextWeight, nextNode});
            }
        }
    }
}


int main() {
    cin>>n>>e;

    adjList.resize(n+1);
    visited.assign(n+1, false);
    mst.assign(n+1, 1e9);

    for(int i=0;i<e;i++){
        int from, to, weight;

        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    prim(1);

    int ans=0;

    for(auto it:mst){
        if(it!=1e9){
            ans+=it;
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}