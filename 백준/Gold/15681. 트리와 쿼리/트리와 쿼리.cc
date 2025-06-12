#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> childs;

void dfs(int n){
    childs[n]=1;
    
    for(auto nextNode:adjList[n]){
        if(childs[nextNode]==-1){
            dfs(nextNode);
            childs[n]+=childs[nextNode];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin>>n>>r>>q;

    adjList.resize(n+1);
    childs.assign(n+1, -1);

    for(int i=0;i<n-1;i++){
        int from, to;
        cin>>from>>to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    dfs(r);
    // for(auto c:childs) cout<<c<<" ";
    // cout<<"\n";

    for(int i=0;i<q;i++){
        int node;
        cin>>node;
        
        cout<<childs[node]<<"\n"; 
    }
    
    
    return 0;
}