#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int tabulation(int n){
    if(n==0||n==1){
        return n;
    }

    dp[0]=0,dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main(void){
    int input;

    cin>>input;

    dp.resize(45+1);

    cout<<tabulation(input)<<"\n";
        

    return 0;
}