#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long int> dp;

long long int tabulation(int n){
    if(n==1 || n==2){
        return 1;
    }
    
    //점화식 탈출값을 dp에 초기화
    dp[1]=1, dp[2]=1;

    for(int i=3;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];    
}

int main() {
    int digit;
    dp.resize(91);

    cin>>digit;

    cout<<tabulation(digit)<<"\n";

    return 0;
}