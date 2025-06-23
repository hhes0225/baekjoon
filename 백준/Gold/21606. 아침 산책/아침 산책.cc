#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<bool> isInside;
vector<bool> visited;
int ans=0;

/*
    https://e-juhee.tistory.com/entry/python-%EB%B0%B1%EC%A4%80-21606-%EC%95%84%EC%B9%A8-%EC%82%B0%EC%B1%85-DFS?category=1097015

    실내지점에 대해 dfs를 수행하며 경우를 더하지 말고
    실외지점에 대해 dfs를 수행하며 인접 노드 중 실내가 몇 개 있는지 체크하고
    인접 실내노드=n개라면
    n*(n-1) 개의 경로 있을 수 있음
    nP2 순열(시작점으로 실내 1개 고르면 그 장소는 도착점 될 수 없음)

    실내-실내 의 경우는 따로 체크해서 개수 *2 해주기
    (4-5 경로 != 5-4경로)
*/

int dfs(int curNode){
    visited[curNode]=true;

    // if(isInside[curNode]) return 1;

    int count=0;
    
    for(auto nextNode:adjList[curNode]){
        if(isInside[nextNode]){
            count++;
            continue;
        }
        
        //실외일 경우에만 탐색하여 인접 실내 노드 영역 확장
        if(!visited[nextNode] && !isInside[nextNode]){
            count+=dfs(nextNode);
        }
    }

    // cout<<count<<"\n";
    return count;
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

        //실외 거치지 않고 실내-실내 인 경우
        if(isInside[from]&&isInside[to]){
            ans+=2;
        }
    }

    for(int i=1;i<=n;i++){
        if(!isInside[i]&&!visited[i]){//미방문 실외일 경우에만 그래프 순회
            int cnt=dfs(i);
            ans+=(cnt*(cnt-1));
        }
    }

    cout<<ans<<"\n";

    
    return 0;
}