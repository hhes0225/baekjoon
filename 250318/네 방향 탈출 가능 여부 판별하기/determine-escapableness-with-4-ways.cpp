#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> visited;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

bool canMove(int r, int c){
    return (r>=0&&r<n&&c>=0&&c<m);
}


void BFS(int r,int c){
    visited[r][c]=true;
    queue<pair<int, int>> q;
    q.push({r,c});

    while(!q.empty()){
        auto [curR, curC]=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextR=curR+dr[i];
            int nextC=curC+dc[i];

            if(!canMove(nextR, nextC)) continue;    
            
            if(visited[nextR][nextC]) continue;
            if(a[nextR][nextC]==0) continue;//이동 불가

            visited[nextR][nextC]=true;
            q.push({nextR, nextC});
        }
    }
}

int main() {
    cin >> n >> m;

    a.resize(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    BFS(0,0);

    if(visited[n-1][m-1]) cout<<1<<"\n";
    else cout<<0<<"\n";

    return 0;
}
