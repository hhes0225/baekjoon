#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000009

vector<unsigned long long int> dp;

void memoi(){
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int i=4;i<dp.size();i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]) % MOD;
    }
}

int main() {
    int tCase;
    dp.resize(1000000+1);

    cin>>tCase;

    memoi();

    for(int i=0;i<tCase;i++){
        int idx;
        cin>>idx;
        
        cout<<dp[idx]<<"\n";
    }
    
    return 0;
}