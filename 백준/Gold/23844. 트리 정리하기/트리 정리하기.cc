#include <bits/stdc++.h>
using namespace std;

/*
    https://burningfalls.github.io/algorithm/boj-23844/

    dfs
    세대별 노드 개수, 각 노드가 몇 세대에 속하는지, 각 노드의 부모 노드
    해당 노드의 자식 노드가 몇 개인지
*/
typedef pair<int, int> PII;


vector<vector<int>> adjList;
vector<int> parent;
vector<int> child;
vector<vector<int>> generation;



void dfs(int n, int p, int gen){
    child[n]=1;
    parent[n]=p;
    generation[gen].push_back(n);

    for(auto nextNode:adjList[n]){
        if(child[nextNode]==-1){
            dfs(nextNode, n, gen+1);
            child[n]+=child[nextNode];
        }
    }
}

int main() {
    int n, k;
    cin>>n>>k;

    int ans=n;

    adjList.resize(n+1);
    parent.resize(n+1);
    generation.resize(n+1);
    child.assign(n+1, -1);

    for(int i=0;i<n;i++){
        int from, to;
        cin>>from>>to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    dfs(1, 0, 1);

    // for(auto i:child){
    //     cout<<i<<" "; 
    // }
    // cout<<"\n";

    // for(auto i:parent){
    //     cout<<i<<" "; 
    // }
    // cout<<"\n";

    // for(auto i: generation){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }

    vector<int> childCpy=child;

    int sub=0;

    for(int i=n;i>0;i--){
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        for(auto j:generation[i]){
            if(j != 1) pq.push({child[j],j});
        }

        while(pq.size()>k){
            auto [childs, node]=pq.top();
            pq.pop();
            
            sub+=childs;

            if(parent[node] !=0)
                child[parent[node]]-=childCpy[node];
        }
    }

    cout<<n-sub<<"\n";
    
    return 0;
}