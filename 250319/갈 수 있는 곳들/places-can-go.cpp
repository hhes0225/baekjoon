#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> startPoint;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

void BFS(int r, int c){
    visited[r][c]=true;
    queue<pair<int, int>> q;
    q.push({r, c});

    while(!q.empty()){
        auto [curR, curC]=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextR=curR+dr[i];
            int nextC=curC+dc[i];

            if(nextR<0||nextR>=n||nextC<0||nextC>=n) continue;
            if(visited[nextR][nextC]) continue;
            if(grid[nextR][nextC]==1) continue;

            visited[nextR][nextC]=true;
            q.push({nextR, nextC}) ;
        }
    }
}

int main() {
    cin >> n >> k;

    grid.resize(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    startPoint.resize(k);

    for(auto &i:grid){
        for(auto &j:i){
            cin>>j;
        }
    }


    for(auto &s:startPoint){
        cin>>s.first>>s.second;
    }


    for(auto s:startPoint){
        BFS(s.first-1, s.second-1);
    }

    int area=0;
    for(auto i:visited){
        for(auto j:i){
            if(j) area++;
        }
    }

    cout<<area<<"\n";


    return 0;
}
