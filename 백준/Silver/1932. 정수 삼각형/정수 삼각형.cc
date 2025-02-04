#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triangle;
vector<vector<int>> dp;

int maxSum(int n){
    dp[0][0]=triangle[0][0];
    //dp[1][0]=dp[0][0]+triangle[1][0];
    //dp[1][1]=dp[0][0]+triangle[1][1];

    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+triangle[i][0];
        dp[i][dp[i].size()-1]=dp[i-1][dp[i-1].size()-1]+triangle[i][triangle[i].size()-1];
        for(int j=1;j<i;j++){
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
        }
    }

    return *max_element(dp[n-1].begin(), dp[n-1].end());
}

int main() {
    int n;
    cin>>n;

    triangle.resize(n);
    dp.resize(n);

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            int tmp;
            cin>>tmp;
            triangle[i-1].push_back(tmp);
            dp[i-1].push_back(0);
        }
    }

    /*
    for(auto i:triangle){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    */

    cout<<maxSum(n)<<"\n";

    /*
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    */
    return 0;
}