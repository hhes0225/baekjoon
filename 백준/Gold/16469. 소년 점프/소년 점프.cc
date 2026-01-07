#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef pair<int, int> PII;

vvc grid;
vvi nDist, sDist, cDist;
vvi result;
vector<int> res;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int n, m;

void bfs(vvi& target, int r, int c){
    target[r][c]=0;
    queue<PII> q;
    q.push({r,c});
    
    while(!q.empty()){
        auto [curR, curC]=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nextR=curR+dr[i];
            int nextC=curC+dc[i];
            
            if(nextR<0||nextR>=n||nextC<0||nextC>=m) continue;
            
            if(grid[nextR][nextC]=='1') continue;
            if(target[nextR][nextC]>=0) continue;
            
            target[nextR][nextC]=target[curR][curC]+1;
            q.push({nextR, nextC});
        }
    }
}

int main()
{
    int nr, nc;
    int sr, sc;
    int cr, cc;
    
    cin>>n>>m;
    
    grid.resize(n, vector<char>(m));
    nDist.assign(n, vector<int>(m,-1));
    sDist.assign(n, vector<int>(m,-1));
    cDist.assign(n, vector<int>(m,-1));
    result.assign(n, vector<int>(m,-1));
    res.assign(n*m, 0);

    for(auto&i:grid){
        for(auto&j:i){
            cin>>j;
        }
    }
    
    // for(auto&i:grid){
    //     for(auto&j:i){
    //         cout<<j;
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    
    cin>>nr>>nc>>sr>>sc>>cr>>cc;
    
    bfs(nDist, nr-1, nc-1);
    bfs(sDist, sr-1, sc-1);
    bfs(cDist, cr-1, cc-1);
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nDist[i][j]<0||sDist[i][j]<0||cDist[i][j]<0) continue;
            
            res[max({nDist[i][j], sDist[i][j], cDist[i][j]})]++;
        }
    }
    
    // for(auto i:res){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    
    bool canReach=false;
    
    for(int i=0;i<res.size();i++){
        if(res[i]==0) continue;
        else{
            canReach=true;
            cout<<i<<"\n"<<res[i]<<"\n";
            break;
        }
    }
    
    if(!canReach){
        cout<<"-1\n";
    }
    

    return 0;
}