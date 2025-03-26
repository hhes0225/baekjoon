#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<char>> grid;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int minDist=INT_MAX;
int coinCnt=0;
vector<int> choice;

vector<vector<bool>> visited;

void backtracking(int r, int c, int prevCoin, int dist){
    if(dist>=minDist) return;
    //탈출조건
    if(grid[r][c]=='E'){
        if(choice.size()>=3){
            minDist=min(minDist, dist);

            // for(auto i:visited){
            //     for(auto j:i) cout<<j<<" ";
            //     cout<<"\n";
            // }

            // cout<<"\n";
            // for(auto c:choice) cout<<c<<" ";
            // cout<<"\n";
            // cout<<"----------------\n";


        }
        return;
    }

    for(int i=0;i<4;i++){
        int nextR=r+dr[i];
        int nextC=c+dc[i];
        

        if(nextR<0||nextR>=N||nextC<0||nextC>=N) continue;
        if(visited[nextR][nextC]) continue;

        char coinVal=grid[nextR][nextC];

        if(coinVal>='0'&&coinVal<='9'&&prevCoin<coinVal-'0'){
            //증가하는 순서대로만 동전 수집 가능
            //해당 칸 동전 수집할 때
            visited[nextR][nextC]=true;
            choice.push_back(coinVal-'0');
            backtracking(nextR, nextC, coinVal-'0', dist+1);

            visited[nextR][nextC]=false;
            choice.pop_back();
        }
        

        visited[nextR][nextC]=true;
        //해당 칸 동전 수집하지 않을 때
        backtracking(nextR, nextC, prevCoin, dist+1);
        visited[nextR][nextC]=false;

        
    }
    
}

int main() {
    cin >> N;

    grid.resize(N, vector<char>(N));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    // Please write your code here.
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]=='S'){
                backtracking(i,j,0,0);
            }
        }
    }

    if(minDist==INT_MAX) cout<<-1<<"\n";
    else cout<<minDist<<"\n";

    return 0;
}
