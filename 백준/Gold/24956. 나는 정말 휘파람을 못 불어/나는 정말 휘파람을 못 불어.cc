#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;

vector<int> dp(4);
/*
dp[0]: 현재까지의 "W"로 시작하는 부분 수열의 개수
dp[1]: 현재까지의 "WH"로 시작하는 부분 수열의 개수
dp[2]: 현재까지의 "WHE"로 시작하는 부분 수열의 개수
dp[3]: 현재까지의 "WHE...E"와 같은 유사 휘파람 문자열의 개수
*/

int main() {
    int n;
    string s;

    cin>>n>>s;

    for(auto it:s){
        if(it=='E'){
            //'유사 휘파람 문자열' 뒤에 E를 붙인 것+새로 추가된 유사 휘파람 문자열
            dp[3]+=dp[3];
            dp[3]%=MOD;
            dp[3]+=dp[2];
            dp[3]%=MOD;
            
            dp[2]+=dp[1];
            dp[2]%=MOD;
        }
        //WH
        else if(it=='H'){
            dp[1]+=dp[0];
            dp[1]%=MOD;
        }
        //W
        else if(it=='W'){
            dp[0]++;
            dp[0]%=MOD;
        }
    }
    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    cout<<dp[3]<<"\n";
    
    return 0;
}