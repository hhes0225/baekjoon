#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

vector<vector<PII>> adjList;
vector<bool> visited;
vector<int> result;
int n;
int farthestNode=0;//가장 긴 거리를 가진 노드
int maxDist=0;//해당 노드에서의 가장 긴 거리

/*
    dfs 2번으로 해결되는 문제.
    이때, 최장 거리와 그때의 노드도 구해야 한다.
    dfs 1st: 임의의 노드에서 최장 거리를 가진 노드를 구해서,
    dfs 2nd: 1st에서 구한 최장 거리 노드의 최장 거리를 가진 또 다른 노드를 구한다.
    
    확률적으로 1에서 가장 거리 먼 노드로 시작했을 때 가장 거리 먼 노드를 찾을 확률이 높기 때문
    
*/

void dfs(int node, int dist){
    visited[node]=true;

    if(dist>maxDist){
        maxDist=dist;
        farthestNode=node;
    }

    for(int i=0;i<adjList[node].size();i++){
        int nextNode=adjList[node][i].first;
        int nextWeight=adjList[node][i].second;

        if(!visited[nextNode]){
            dfs(nextNode, dist+nextWeight);
        }
    }
}


int main() {
    cin>>n;

    adjList.resize(n+1);
    visited.assign(n+1, false);

    for(int i=0;i<n;i++){
        int from;
        cin>>from;

        while(1){
            int to, weight;
            
            cin>>to;
            if(to==-1){
                break;
            }
            cin>>weight;

            //양방향 그래프!!
            adjList[from].push_back({to, weight});
            adjList[to].push_back({from, weight});
        }
    }

    //1. 임의의 노드에서 가장 먼 노드와 그때의 거리를 구한다.
    maxDist=0;
    fill(visited.begin(), visited.end(), 0);
    dfs(1, 0);

    //2에서 구해진 가장 거리 먼 노드(farthestNode)에서 
    //가장 거리가 먼 노드를 구한다.
    maxDist=0;
    fill(visited.begin(), visited.end(), 0);
    dfs(farthestNode, 0);

    cout<<maxDist<<"\n";
    return 0;
}