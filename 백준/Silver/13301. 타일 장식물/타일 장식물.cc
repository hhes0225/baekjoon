#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dp;

ll getTileLen(int n){
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    
    return dp[n]*2+dp[n-1]*2;
}

int main() {
    int n;
    cin>>n;

    dp.assign(n+2, 0);

    cout<<getTileLen(n+1)<<"\n";
    
    return 0;
}