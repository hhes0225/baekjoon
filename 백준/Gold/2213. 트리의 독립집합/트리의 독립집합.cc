#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int dp[10100][2];
int weight[10100];
int visited[10100];
bool tracking[10100];
vector<int> tree[10100];

void dfs(int cur){
    if(visited[cur])
        return;
    visited[cur] = 1;
    dp[cur][0] = 0;
    dp[cur][1] = weight[cur];
    for(auto next : tree[cur]){
        if(visited[next])
            continue;
        dfs(next);
        if(dp[next][1] > dp[next][0]){
            dp[cur][0] += dp[next][1];
            tracking[next] = 1;
        }
        else{
            dp[cur][0] += dp[next][0];
            tracking[next] = 0;
        }
        dp[cur][1] += dp[next][0];
    }
}

void track(int cur, bool chk){
    if(visited[cur])
        return;
    visited[cur] = 1;
    if(chk){
        ans.push_back(cur);
        for(auto next : tree[cur]){
            if(visited[next])
                continue;
            track(next,0);
        }
    }
    else{
        for(auto next : tree[cur]){
            if(visited[next])
                continue;
            track(next,tracking[next]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //input
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>weight[i];
    for(int i=1; i<n; i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    //tree dp
    dfs(1);
    //예외 처리
    if(dp[1][1]>dp[1][0]) tracking[1] = 1;
    else tracking[1] = 0;
    //역추적
    memset(visited,0,sizeof(visited));
    track(1,tracking[1]);
    //output
    cout << max(dp[1][1],dp[1][0]) << '\n';
    sort(ans.begin(),ans.end());
    for(auto i : ans)
        cout << i << ' ';
    return 0;
}