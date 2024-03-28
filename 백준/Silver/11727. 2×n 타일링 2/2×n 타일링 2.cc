#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int tabulation(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 3;
    }

    dp[1]=1, dp[2]=3;
    for(int i=3;i<n+1;i++){
        //dp[i]=(3*dp[i-2]+(dp[i-1]-dp[i-2]))%10007;
        dp[i]=(2*dp[i-2]+dp[i-1])%10007;
    }

    return dp[n];
}

int main(void){
    int input;
    cin>>input;

    dp.resize(1000+1);

    cout<<tabulation(input)<<"\n";
    
    return 0;
}