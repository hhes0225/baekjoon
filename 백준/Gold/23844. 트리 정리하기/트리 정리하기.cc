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


/*

    child: n을 루트로 한 서브트리 구성 노드 개수(자기 자신을 포함한 총 자식 개수)
    parent: n의 부모노드
    generation[gen]: gen 세대에 속하는 노드 리스트
*/
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

    //child: 가지치기 후 현재 남아있는 실제 서브트기 크기
    //childCpy: 원래 서브트리 크
    vector<int> childCpy=child;

    int sub=0;

    //가장 후세대(깊은 노드)부터 순회
    for(int i=n;i>0;i--){
        priority_queue<PII, vector<PII>, greater<PII>> pq;//자식 가장 적은 노드부터 제거
        
        for(auto j:generation[i]){
            if(j != 1) pq.push({child[j],j});
        }

        while(pq.size()>k){
            auto [childs, node]=pq.top();
            pq.pop();
            
            sub+=childs;//제거할 노드의 자식들 더해주고

            if(parent[node] !=0)
                child[parent[node]]-=childCpy[node];//이를 부모 노드에 반영
            //cpy를 빼야 할아버지 세대도 정확하게 끊어진 것을 반영 가능함

            /*
                그런데 만약 부모의 child[] 값을 단순히 childs(= 현재 남은 서브트리 크기) 만큼만 뺀다면...

                이미 손자 중 몇 명이 다른 레벨에서 먼저 잘려 나간 경우,
                childs는 이미 줄어든 값이기 때문에
                할아버지(그 위 조상) 레벨에서는 실제로 없어진 자손 수를 제대로 반영 못하게 됩니다.
            */
        }
    }

    cout<<n-sub<<"\n";
    
    return 0;
}