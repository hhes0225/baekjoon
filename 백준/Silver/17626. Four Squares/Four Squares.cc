#include <bits/stdc++.h>
#define MAX 50'000
using namespace std;

vector<int> dp;
vector<int> power;

/*
    내가 생각한 점화식
    power[i]: MAX 이하의 제곱수들
    dp[j]: 숫자 j의 최소 개수의 제곱수 합

    power(제곱수들)을 순회하면서
    dp[j]=min(dp[j], dp[j-제곱수]+1)

    왜냐??
    일단 power의 최대 길이가 223 정도고(sqrt(50000))
    dp 최대가 MAX 이기 때문에 최대 1'500'000회로 연산 횟수 시간 이내임.

    그리고 규칙적으로
    예를 들어
    1-1
    2-1+1 == 1 + dp[2-1]
    3-1+1+1==1+dp[3-1]
    4-1(4 자체가 제곱수)
    5-4+1 -> 2(1(범위 내 최대 제곱수)+dp[5-4])
    6-4+1+1 -> 3
    7-4+dp[7-4=3]->4
    8-4+dp[8-4=4]->2
    이렇게 가는 규칙이 있음.
*/

int dpFunc(int n){
    dp[0]=0;
    //제곱수일 경우 제곱수-제곱수가 되어서 0 인덱스에 접근할거임. 그때를 대비
    //이때 1+dp[0]이 될 것이기 때문에 0으로 설정해야 제곱수일 때 1개의 수로 표현 가능하다고
    //저장할 수 있다.
    dp[1]=1;

    for(int i=0;i<power.size();i++){
        for(int j=power[i];j<=n;j++){
            //cout<<dp[j]<<" "<<1+dp[j-power[i]]<<" "<<j-power[i]<<"\n";
            dp[j]=min(dp[j], 1+dp[j-power[i]]);
 
        }
    }

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    
    return dp[n];
}

int main() {
    int n;
    cin>>n;

    dp.assign(n+1, MAX);

    for(int i=1;i<=n;i++){
        if(pow(i,2)>n){
            break;
        }
        power.push_back(pow(i,2));
    }

    /*
    for(auto it:power){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    cout<<dpFunc(n)<<"\n";
    
    return 0;
}