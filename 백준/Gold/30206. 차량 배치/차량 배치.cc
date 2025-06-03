#include <bits/stdc++.h>
using namespace std;
const int MOD=1'000'000'007;



//거리는 도달 시간과 비례
//같은 시간에는 하나의 차량만 존재해야 함.

/*
    모든 지점에 대해 두 가지 경우의 수가 있음:
    차량 배치하거나 or 배치하지 않거나.

    1번 지점을 루트로 두고, 루트에 대해 모든 자식 노드 간 거리를 구함.
    
    1수준 떨어져 있는 노드: 2,3
    2수준 떨어져 있는 노드: 4,5,6
    이라면,
    1수준 노드들 중 차량 1대만 배치
    2수준 노드들 중 차량 1대만 배치
    해야 충돌이 나지 않음.

    이때 최소 1대 이상의 차량을 배치해야 하므로,
    모든 차량을 배치하지 않는 1가지 경우의 수를 배제함.

    따라서
    (1수준 노드들+1)*(2수준 노드들+1)*...*(n수준 노드들+1)-1
    (+1은 해당 수준에서 아예 차량을 배치하지 않는 경우)
*/

vector<vector<int>> adjList;
vector<int> visited;
unordered_map<int, int> depth;

void bfs(int n){
    visited[n]=1;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int curNode=q.front();
        q.pop();

        for(auto nextNode:adjList[curNode]){
            if(visited[nextNode]==0){
                visited[nextNode]=visited[curNode]+1;
                q.push(nextNode);
            }
        }
    }

    // for(auto i:visited) cout<<i<<" ";
    // cout<<"\n";
}


int main() {
    int n, m;
    cin>>n>>m;

    adjList.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    for(auto a:adjList){
        sort(a.begin(), a.end());
    }

    bfs(1);

    //0은 없는 노드이므로 제외
    for(int i=1;i<=n;i++){
        depth[visited[i]]++;
    }

    long long ans=1;
    for(auto d:depth){
        ans=(ans*(d.second+1))%MOD;
    }

    cout<<ans-1<<"\n";
    
    
    return 0;
}