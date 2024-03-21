#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int tabulation(int n){
    if(n==1||n==2){
        return n;
    }
    
    dp[1]=1, dp[2]=2;

    for(int i=3;i<n+1;i++){
        dp[i]=(dp[i-1]+dp[i-2])%15746;
        
    }

    return dp[n];

}

int main(void){
    int input;
    cin>>input;

    dp.resize(1000001);

    cout<<tabulation(input)<<"\n";

    return 0;
}