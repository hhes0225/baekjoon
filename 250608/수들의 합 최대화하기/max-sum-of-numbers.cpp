#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;
vector<int> nums;
vector<vector<bool>> visited;
int maxSum=0;

int dr[5]={-1,1,0,0};
int dc[5]={0,0,-1,1};

void backtracking(int colored, int r, int c){
    if(colored==0){
        int tmp=0;

        for(auto n:nums) tmp+=n;
        maxSum=max(maxSum, tmp);

        return;
    }

    for(int i=0;i<4;i++){
        int nextR=r+dr[i];
        int nextC=c+dc[i];

        if(nextR<0||nextR>=n||nextC<0||nextC>=n) continue;
        if(visited[nextR][nextC]) continue;

        visited[nextR][nextC]=true;
        nums.push_back(grid[nextR][nextC]);

        backtracking(colored-1, nextR, nextC);

        visited[nextR][nextC]=false;
        nums.pop_back();
    }
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    backtracking(n, -1,-1);
    cout<<maxSum<<"\n";

    return 0;
}
