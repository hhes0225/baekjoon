#include <bits/stdc++.h>
#define MOD 1'000'000'000
using namespace std;

vector<vector<int>> dp;
//dp[n][i]: 1의 자리 수가 [i]로 끝나는, 길이가 n인 계단 수

int dpFunc(int n){
    //n=1인 수는 무조건 계단수
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i][0]+dp[i-1][1])%MOD;
        for(int j=1;j<9;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
        dp[i][9]=(dp[i][9]+dp[i-1][8])%MOD;
    }

    /*
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */

    //총 계단수의 합 구하기
    int ans=0;
    for(int i=0;i<10;i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    
    return ans;
}

int main() {
    int n;
    cin>>n;

    dp.assign(n+1, vector<int>(10, 0));

    cout<<dpFunc(n)<<"\n";
    return 0;
}