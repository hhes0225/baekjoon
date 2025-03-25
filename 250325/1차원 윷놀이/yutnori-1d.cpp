#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> nums;
vector<int> boardResult;
int maxResult=0;

void backtracking(int turns){
    if(turns==n){
        int tmpResult=0;
        for(auto b:boardResult){
            //cout<<b<<" ";
            if(b>=m) tmpResult++;
        }
        //cout<<"\n";

        maxResult=max(maxResult, tmpResult);

        return;
    }

    for(int i=0;i<k;i++){
        boardResult[i]+=nums[turns];

        backtracking(turns+1);

        boardResult[i]-=nums[turns];
    }
}

int main() {
    cin >> n >> m >> k;

    nums.resize(n);
    boardResult.assign(k, 1);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    backtracking(0);
    cout<<maxResult<<"\n";

    return 0;
}
