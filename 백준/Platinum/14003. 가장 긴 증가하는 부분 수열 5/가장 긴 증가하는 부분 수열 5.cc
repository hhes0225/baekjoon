#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> nums;
vector<int> dp;//인덱스 저장
//dp[i]: i까지의 최장 길이

vector<int> lisLen;//최장길이(길이만 정확, 요소&순서는 안정확)
vector<int> lisResult;//최종 LIS(요소, 순서도 정확)

//참고: https://seongmok.com/21

void LIS(int n){
    dp[0]=1;
    lisLen.push_back(nums[0]);

    //LIS 최장길이 구하기(O(nlogn): 이분탐색/lower bound 활용)
    for(int i=1;i<n;i++){
        auto it=lower_bound(lisLen.begin(), lisLen.end(), nums[i]);

        if(it!=lisLen.end()){//lisLen에 이거보다 큰게 있으면
            *it=nums[i];
            dp[i]=it-lisLen.begin()+1;
        }
        else{//lisLen에 이거보다 큰게 없으면
            lisLen.push_back(nums[i]);
            dp[i]=lisLen.size();
        }
    }
    
    cout<<lisLen.size()<<"\n";
    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    //dp 배열에서 최장 LIS 가 형성되는 과정을 보고,
    //nums 배열에 적용하여 길이 뿐 아니라 정확한 LIS를 생성
    int maxIdx=max_element(dp.begin(), dp.end())-dp.begin();
    lisResult.push_back(nums[maxIdx]);
    for(int i=maxIdx-1;i>=0;i--){
        if(dp[i]+1==dp[maxIdx]){
            maxIdx=i;
            lisResult.push_back(nums[maxIdx]);
        }
    }

    //가장 큰 수->작은 수로 가므로 reverse 해야 LIS(가장 긴 증가하는 수열)
    //올바르게 출력 가능
    reverse(lisResult.begin(), lisResult.end());
    for(auto it:lisResult){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main() {
    int n;
    cin>>n;

    nums.resize(n);
    dp.resize(n);

    for(auto& it:nums){
        cin>>it;
    }

    LIS(n);
    
    return 0;
}