#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int n, q;
vector<vector<PII>> adjList;

int bfs(int k, int v){
    vector<int> visited(n+1, INT_MAX);
    
    visited[v]=INT_MAX-1;
    queue<PII> q;
    q.push({visited[v], v});

    while(!q.empty()){
        auto [curW, curN]=q.front();
        q.pop();

        for(auto [nextW, nextN]:adjList[curN]){
            if(visited[nextN]==INT_MAX){
                visited[nextN]=min(nextW, curW);
                q.push({visited[nextN], nextN});
            }
        }
    }

    int cnt=0;

    // for(auto vi:visited){
    //     cout<<vi<<" ";
    // }
    // cout<<"\n";
    
    for(auto vi:visited){
        if(vi==INT_MAX||vi==INT_MAX-1) continue;
        if(vi>=k) cnt++;
    }

    return cnt;
}


int main() {
    cin>>n>>q;

    adjList.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    for(int i=0;i<q;i++){
        int k, v;
        cin>>k>>v;

        cout<<bfs(k, v)<<"\n";
    }
    
    return 0;
}