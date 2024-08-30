#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> dp;

/*
    가장 큰 증가하는 부분 수열의 합 LIS

    dp[i]: i번째 인덱스까지에서 가장 큰 증가하는 부분 수열

    dp 0 ~ i-1 범위 중에서 nums[i]보다 크다면,
    max(dp[i], dp[n(num이 더 작은 인덱스)]+nums[i])값
    으로 갱신

    만약 크지 않다면
    max(dp[i], nums[i]);
    dp[i]가 0으로 초기화된 상태거나 현재 num값보다 작다면 num값으로 갱신
    그렇지 않다면 dp[i] 값으로 유지
    
*/

int memoi(){
    dp[0]=nums[0];

    for(int i=1;i<dp.size();i++){
        for(int j=0;j<=i-1;j++){
            if(nums[i]>nums[j]){
                //cout<<"nums[i]: "<<nums[i]<<", nums[j]: "<<nums[j]<<endl;
                //cout<<dp[i]<<", "<<dp[j]+nums[i]<<"\n";
                dp[i]=max(dp[i], dp[j]+nums[i]);
                
            }
            else{
                dp[i]=max(dp[i], nums[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int tCase;
    cin>>tCase;

    nums.resize(tCase);
    dp.assign(tCase, 0);
    
    for(int i=0;i<tCase;i++){
        cin>>nums[i];
    }

    int result = memoi();

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
        
    cout<<result<<"\n";
    
    return 0;
}