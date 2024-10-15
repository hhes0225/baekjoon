#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

vector<vector<PII>> adjList;
vector<bool> visited;
int maxDist=0, farthestNode=0;
int n;

void dfs(int node, int dist){
    visited[node]=true;

    if(dist>maxDist){
        maxDist=dist;
        farthestNode=node;
    }

    for(int i=0;i<adjList[node].size();i++){
        int nextNode = adjList[node][i].first;
        int nextWeight = adjList[node][i].second;

        if(!visited[nextNode]){
            dfs(nextNode, dist+nextWeight);
        }
    }
}

int main() {
    cin>>n;
    adjList.resize(n+1);
    visited.assign(n+1, false);
    

    for(int i=0;i<n-1;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    }

    fill(visited.begin(), visited.end(), false);
    maxDist=0;
    dfs(1, 0);
    
    fill(visited.begin(), visited.end(), false);
    maxDist=0;
    dfs(farthestNode, 0);

    cout<<maxDist<<"\n";
    
    return 0;
}