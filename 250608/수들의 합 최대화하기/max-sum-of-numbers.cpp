#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;
vector<int> nums;
vector<int> visitedCol;
int maxSum=0;

void backtracking(int colored, int r){
    if(colored==0){
        int tmp=0;

        for(auto n:nums) tmp+=n;
        maxSum=max(maxSum, tmp);
        
        // for(auto n:nums) cout<<n<<" ";
        // cout<<"="<<tmp<<"\n";

        return;
    }

    for(int j=0;j<n;j++){
        if(visitedCol[j]) continue;

        visitedCol[j]=true;
        nums.push_back(grid[r][j]); 

        backtracking(colored-1, r+1);

        visitedCol[j]=false;
        nums.pop_back();
    }
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    visitedCol.assign(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    backtracking(n, 0);
    cout<<maxSum<<"\n";

    return 0;
}
