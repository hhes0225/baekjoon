#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int getMaxProfit(int init, int n){
    dp[0]=init;

    for(int i=1;i<=n;i++){
        if(i>=5){
            dp[i]=max({dp[i-1]*1.05, dp[i-3]*1.2, dp[i-5]*1.35});
        }
        else if(i>=3){
            dp[i]=max(dp[i-1]*1.05, dp[i-3]*1.2);
        }
        else{
            dp[i]=dp[i-1]*1.05;
        }
    }

    /*
    for(auto d : dp){
        cout<<d<<" ";
    }
    cout<<"\n";
    */

    return dp[n];
}

int main() {
    int h, y;

    cin>>h>>y;
    dp.assign(y+1, 0);

    cout<<getMaxProfit(h, y)<<"\n";
    
    return 0;
}