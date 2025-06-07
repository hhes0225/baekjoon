#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;
vector<int> nums;
vector<int> visitedRow;
vector<int> visitedCol;
int maxSum=0;

int dr[5]={0, -1,1,0,0};
int dc[5]={0,0,0,-1,1};

void backtracking(int colored, int r, int c){
    if(colored==0){
        int tmp=0;

        for(auto n:nums) tmp+=n;
        maxSum=max(maxSum, tmp);
        
        // for(auto n:nums) cout<<n<<" ";
        // cout<<"="<<tmp<<"\n";

        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visitedRow[i] || visitedCol[j]) continue;

            // cout<<"컷안됐다\n";

            visitedRow[i]=true;
            visitedCol[j]=true;
            nums.push_back(grid[i][j]); 
            // cout<<nums.back()<<"\n";

            backtracking(colored-1, i, j);

            visitedRow[i]=false;
            visitedCol[j]=false;
            nums.pop_back();
        }
    }
    // for(int i=0;i<5;i++){
    //     int nextR=r+dr[i];
    //     int nextC=c+dc[i];

    //     if(nextR<0||nextR>=n||nextC<0||nextC>=n) continue;
    //     if(visitedRow[nextR] || visitedCol[nextC]) continue;

    //     // cout<<"컷안됐다\n";

    //     visitedRow[nextR]=true;
    //     visitedCol[nextC]=true;
    //     nums.push_back(grid[nextR][nextC]); cout<<nums.back()<<"\n";

    //     backtracking(colored-1, nextR, nextC);

    //     visitedRow[nextR]=false;
    //     visitedCol[nextC]=false;
    //     nums.pop_back();
    // }
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    visitedRow.assign(n, false);
    visitedCol.assign(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    backtracking(n, 0,0);
    cout<<maxSum<<"\n";

    return 0;
}
