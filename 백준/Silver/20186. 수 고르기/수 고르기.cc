#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> nums;
    nums.resize(n);

    for(auto &i:nums){
        cin>>i;
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int maxSum=0;
    for(int i=0;i<k;i++){
        // cout<<nums[i]<<" "<<i<<"\n";
        maxSum+=(nums[i]-i);
    }
    cout<<maxSum<<"\n";
    
    return 0;
}