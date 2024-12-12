#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int dpFunc(int n){
    dp[0]=0;
    dp[1]=0;

    for(int i=2;i<=n;i++){
        int div3=987'654'321;
        int div2=987'654'321;
        int sub1=dp[i-1];

        if(i%3==0){
            div3=dp[i/3];
        }
        if(i%2==0){
            div2=dp[i/2];
        }

        dp[i]=min({div3, div2, sub1})+1;
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

    dp.assign(n+1, 0);

    cout<<dpFunc(n)<<"\n";
    
    return 0;
}