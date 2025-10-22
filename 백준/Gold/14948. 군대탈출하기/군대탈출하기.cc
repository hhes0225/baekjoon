#include <bits/stdc++.h>
using namespace std;

const int MAX=1'000'000'000;

vector<vector<int>> grid;
vector<vector<vector<bool>>> visited;
//visites[row][col][점프여부]
//row,col,0: 점프 안쓰고 도착
//row.col,1: 점프하고 도착


int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};

int dr2[4]={0,0,-2,2};
int dc2[4]={-2,2,0,0};

const int NOTJUMPED=0;
const int JUMPED=1;


//level 제한이 limit일 때, 탈출이 가능한가?
bool bfs(int n, int m, int limit){
    visited.assign(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    
    if(grid[0][0]>limit) return false;
    
    visited[0][0][NOTJUMPED]=true;

    queue<tuple<int, int, int>> q;
    q.push({0,0,NOTJUMPED});

    while(!q.empty()){
        auto[curR, curC, curJump]=q.front();
        q.pop();

        if(curR==n-1 && curC==m-1) return true;

        //한 칸 이동
        for(int i=0;i<4;i++){
            int nextR=curR+dr[i];
            int nextC=curC+dc[i];

            if(nextR<0||nextR>=n||nextC<0||nextC>=m){
                continue;
            }

            if(grid[nextR][nextC]>limit){
                continue;
            }

            if(visited[nextR][nextC][curJump]) continue;

            visited[nextR][nextC][curJump]=true;
            q.push({nextR, nextC, curJump});
        }

        //점프 가능하면 점프
        if(curJump==NOTJUMPED){
            for(int i=0;i<4;i++){
                int nextR=curR+dr2[i];
                int nextC=curC+dc2[i];
    
                if(nextR<0||nextR>=n||nextC<0||nextC>=m){
                    continue;
                }
    
                if(grid[nextR][nextC]>limit){
                    continue;
                }
    
                if(visited[nextR][nextC][JUMPED]) continue;
    
                visited[nextR][nextC][JUMPED]=true;
                q.push({nextR, nextC, JUMPED});
            }
        }
    }

    return false;
}

int main() {
    int ans;
    
    int n, m;
    cin>>n>>m;

    grid.resize(n, vector<int>(m));
    

    for(auto&i:grid){
        for(auto&j:i){
            cin>>j;
        }
    }

    int low=0, high=MAX;
    ans=high+1;

    while(low<=high){
        int mid=(low+high)/2;

        if(bfs(n,m,mid)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<low<<"\n";
    
    return 0;
}