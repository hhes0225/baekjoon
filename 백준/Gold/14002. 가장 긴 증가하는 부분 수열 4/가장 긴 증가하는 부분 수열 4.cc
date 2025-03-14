#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

void dp(int n){
    vector<int> lis;
    vector<int> dpTable(n, 0);

    for(int i=0;i<n;i++){
        auto pos=lower_bound(lis.begin(), lis.end(), nums[i]);
        //lis에서 n보다 같거나 큰 값
        
        if(pos!=lis.end()){//있으면
            *pos=nums[i];    
            dpTable[i]=pos-lis.begin()+1;
        }
        else{
            lis.push_back(nums[i]);
            dpTable[i]=lis.size();
        }
    }

    /*for(auto l:lis) cout<<l<<" ";
    cout<<"\n";
    for(auto d:dpTable) cout<<d<<" ";
    cout<<"\n";*/

    cout<<lis.size()<<"\n";
    //이 경우 크기는 맞으나, 내용물이 맞는지 알 수 없음

    //dp에서 실제 lis 수열로 원복
    int maxVal=*max_element(dpTable.begin(), dpTable.end());
    int maxIdx=max_element(dpTable.begin(), dpTable.end())-dpTable.begin();
    vector<int> ans;
    
    ans.push_back(nums[maxIdx]);

    for(int i=maxIdx-1;i>=0;i--){
        if(dpTable[i]==maxVal-1){
            ans.push_back(nums[i]);
            maxVal--;
            maxIdx=i;
        }
    }

    //큰->작으로 push했으므로 reverse
    reverse(ans.begin(), ans.end());

    for(auto a:ans) cout<<a<<" ";
    cout<<"\n";
}

int main() {
    int n;
    
    cin>>n;
    nums.resize(n);

    for(auto &i:nums){
        cin>>i;
    }

    //for(auto i:nums) cout<<i<<" ";
    //cout<<"\n";
    
    dp(n);

    
    return 0;
}