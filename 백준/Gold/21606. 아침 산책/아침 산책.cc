#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<bool> isInside;
vector<bool> visited;
int ans=0;

void dfs(int curNode, int prevNode){
    visited[curNode]=true;

    //prevNode==0일 경우 시작점이므로 도착점이 없는 상태.
    //따라서 도착점 조건 체크하지 않음
    if(prevNode!=0 && isInside[curNode]){
        // cout<<"경우 +1\n";
        ans++;
        return;
    }

    for(auto nextNode:adjList[curNode]){
        if(!visited[nextNode]){
            dfs(nextNode, curNode);
        }
    }
}

int main() {
    int n;
    cin>>n;

    adjList.resize(n+1);
    isInside.resize(n+1);
    visited.resize(n+1);

    string places;
    cin>>places;

    for(int i=0;i<places.size();i++){
        if(places[i]=='1') isInside[i+1]=true;//isInside는 1-base
        else isInside[i+1]=false;
    }

    for(int i=0;i<n-1;i++){
        int from, to;
        cin>>from>>to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    for(int i=1;i<=n;i++){
        fill(visited.begin(), visited.end(), false);//방문 정보 초기화
        if(isInside[i]){//실내일 경우에만 그래프 순회
            dfs(i, 0);
        }
    }

    cout<<ans<<"\n";

    
    return 0;
}