#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<bool> visited;
vector<int> reassign;
int maxVal=0;

void backtracking(int lim, int idx){
    if(lim==0){
        // for(auto i:reassign) cout<<i<<" ";
        // cout<<"\n";
        
        int value=0;

        for(int i=1;i<n;i++){
            value+=abs(reassign[i-1]-reassign[i]);
        }

        maxVal=max(maxVal, value);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            reassign.push_back(nums[i]);
            visited[i]=true;

            backtracking(lim-1, i);

            reassign.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    cin>>n;
    nums.resize(n);
    visited.assign(n, false);

    for(auto &num:nums) cin>>num;


    backtracking(n, 0);

    cout<<maxVal<<"\n";
    
    return 0;
}