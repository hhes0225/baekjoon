#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> lisLen;
//이때, lisLen은 LIS 길이만 맞고,
//세부적인 요소나 순서는 틀릴 수 있음.

int LIS(int n){
    for(int i=0;i<n;i++){
        auto it = lower_bound(lisLen.begin(), lisLen.end(), nums[i]);

        if(it!=lisLen.end()){
            *it=nums[i];
        }
        else{
            lisLen.push_back(nums[i]);
        }
    }

    return lisLen.size();
}

int main() {
    int n;
    cin>>n;

    nums.resize(n);

    for(auto& it:nums){
        cin>>it;
    }

    cout<<LIS(n)<<"\n";
    
    return 0;
}