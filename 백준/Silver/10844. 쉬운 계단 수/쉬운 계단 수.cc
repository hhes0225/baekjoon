#include <bits/stdc++.h>
#define MOD 1'000'000'000
using namespace std;

vector<vector<long long>> dp;
//dp[len][n]: 길이가 len인 수의 마지막 digit 숫자=n일 경우,
//가능한 계단수의 가짓수

void dpFunc(int n){
    dp[1][0]=0;dp[1][1]=1;
    dp[1][2]=1;dp[1][3]=1;
    dp[1][4]=1;dp[1][5]=1;
    dp[1][6]=1;dp[1][7]=1;
    dp[1][8]=1;dp[1][9]=1;

    for(int i=2;i<=n;i++){
        //0으로 끝나는 수는 이전 마지막 수가 1로 끝나야지만 가능
        dp[i][0]=dp[i-1][1]%MOD;
        
        //1로 끝나는 수는 이전 마지막 수가 0이나 2로 끝나야지만 나올 수 있음
        dp[i][1]=dp[i-1][0]+dp[i-1][2]%MOD;
        dp[i][2]=dp[i-1][1]+dp[i-1][3]%MOD;
        dp[i][3]=dp[i-1][2]+dp[i-1][4]%MOD;
        dp[i][4]=dp[i-1][3]+dp[i-1][5]%MOD;
        dp[i][5]=dp[i-1][4]+dp[i-1][6]%MOD;
        dp[i][6]=dp[i-1][5]+dp[i-1][7]%MOD;
        dp[i][7]=dp[i-1][6]+dp[i-1][8]%MOD;
        dp[i][8]=dp[i-1][7]+dp[i-1][9]%MOD;

        //9로 끝나는 수는 이전 마지막 수가 8로 끝나야지만 나올 수 있음
        dp[i][9]=dp[i-1][8]%MOD;
    }

    
}

int main() {
    int n;
    cin>>n;

    dp.assign(n+1, vector<long long>(10, 0));

    dpFunc(n);

    long long result=0;
    for(int i=0;i<10;i++){
        result+=dp[n][i];
        result%=MOD;
    }
    cout<<result<<"\n";
    
    return 0;
}