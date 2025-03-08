#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> result;
vector<bool> visited;

void recur(int depth){
    if(depth==m){
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){//방문하지 않은 노드만 방문
            visited[i]=true;
            result.push_back(i);
            recur(depth+1);
            //백트래킹 특징!!! 상태를 원복시킨다!!
            visited[i]=false;
            result.pop_back();
        }
    }
}

int main() {
    cin>>n>>m;
    visited.assign(n+1, false);

    recur(0);
    
    return 0;
}