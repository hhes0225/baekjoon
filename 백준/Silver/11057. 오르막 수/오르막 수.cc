#include <bits/stdc++.h>
#define MOD 10'007
using namespace std;

vector<vector<int>> dp;
//dp[len][n]: 길이가 len인 수일때,
//마지막 digit의 숫자가 n일 경우의 오르막 수의 경우의 수

int dpFunc(int n){
    //길이 한자릿수는, 전부 오르막수이므로 반영
    for(int i=0;i<10;i++){
        dp[1][i]=1;
    }

    //모든 len에 대해 마지막 digit가 0인 오르막수는 1개밖에 없음.
    //0, 00, 000, 0000 ...
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }

    //오르막 수 점화식
    //digit가 1 작은 경우+len이 1 작은 경우
    for(int i=2;i<=n;i++){
        for(int j=1;j<10;j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
        }
    }

    /*
    for(auto it:dp){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<"\n";
    }
    */

    int result=0;

    for(int i=0;i<10;i++){
        result+=dp[n][i];
        result%=MOD;
    }

    return result;    
}

int main() {
    int n;

    cin>>n;
    dp.assign(n+1, vector<int>(10, 0));
    
    
    cout<<dpFunc(n)<<"\n";
    
    return 0;
}