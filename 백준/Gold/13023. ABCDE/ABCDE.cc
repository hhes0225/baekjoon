#include <bits/stdc++.h>
using namespace std;
const int ESCAPE=5;

vector<vector<int>> adjList;
vector<bool> visited;
int success=0;

void dfs_backtracking(int prevNode, int node, int depth){
    if(depth==ESCAPE){
        //cout<<"escape:"<<node<<"\n";
        success++;
        return;
    }

    visited[node]=true;

    for(auto nextNode:adjList[node]){
        if(prevNode==nextNode) continue;
        if(!visited[nextNode]){
            //재귀 호출
            dfs_backtracking(node, nextNode, depth+1);
            visited[nextNode]=false;
        }
    }
    //cout<<node<<", "<<depth<<"\n";

    return;
}

int main() {
    int n, m;
    cin>>n>>m;
    
    adjList.resize(n);
    visited.assign(n, false);

    for(int i=0;i<m;i++){
        int f, t;
        cin>>f>>t;

        adjList[f].push_back(t);
        adjList[t].push_back(f);
    }

    for(auto a:adjList){
        sort(a.begin(), a.end());
    }

    /*
    for(auto i:adjList){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }*/

    for(int i=0;i<n;i++){
        fill(visited.begin(), visited.end(), false);
        dfs_backtracking(-1, i, 1);
        //cout<<"-----------\n";

        if(success) break;
    }
    
    //cout<<"cnt: "<<success<<"\n";

    if(success) cout<<1<<"\n";
    else cout<<0<<"\n";
    
    return 0;
}