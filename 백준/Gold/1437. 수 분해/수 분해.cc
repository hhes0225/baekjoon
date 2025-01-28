#include <bits/stdc++.h>
#define MOD 10'007
using namespace std;

vector<int> dp;

int maxDivMul(int n){
    dp[0]=0;
    dp[1]=1; dp[2]=2;
    dp[3]=3; dp[4]=4;

    for(int i=5; i<=n;i++){
        dp[i]=(dp[i-3]*3)%MOD;
    }

    return dp[n];
}

int main() {
    int n;
    cin>>n;

    dp.assign(n+1, 0);

    cout<<maxDivMul(n)<<"\n";
    
    return 0;
}