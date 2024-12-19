#include <bits/stdc++.h>
#define MOD 1'000'000'009
#define MAX 100'000
using namespace std;
typedef long long ll;

/*
    dp[n][i]: n을 1,2,3의 합으로 나타낼 때,
    마지막으로 더한 수가 i인 경우의 경우의 수

    ex)dp[4][1]: 1,2,3의 합으로 4를 나타내는데, 마지막으로 더한 수가 1

    해주는 이유: ""같은 수를 두 번 연속 사용하지 않기 위해""

    점화식)
    dp[i][1] = dp[i-1][2]+dp[i-1][3];
    dp[i][2] = dp[i-2][1]+dp[i-2][3];
    dp[i][3] = dp[i-3][1]+dp[i-3][2];

    ex)
    dp[4][1] = dp[3][2]+dp[3][3];
    //4를 구성할 때, 마지막으로 1을 더하기 위해서는,
    //3에서 마지막에 2를 더했을 경우와, 3을 더했을 경우
    //->...1+1 처럼 연속이 아님
    //ex) 1 2 1, 3 1
    
    dp[4][2] = dp[2][1]+dp[2][3];
    //4를 구성할 때, 마지막으로 2을 더하기 위해서는,
    //2에서 마지막에 1를 더했을 경우와, 3을 더했을 경우
    //->...2+2 처럼 연속이 아님
    //ex) 근데 그런 경우 없음(1+1은 불가, 3으로 2 표현 불가)

    dp[4][3] = dp[1][1]+dp[1][2];
    //4를 구성할 때, 마지막으로 3을 더하기 위해서는,
    //1에서 마지막에 1을 더했을 경우와, 2를 더했을 경우
    //->...3+3 처럼 연속이 아님
    //ex) 1 3
*/

vector<vector<ll>> dp;

void dpFunc(const int n){
    dp[1][1]=1; // 1로 1 만들기
    dp[2][2]=1; // 2로 2 만들기

    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1; // 3으로 3 만들기

    for(int i=4;i<=n;i++){
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD;
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD;
        dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MOD;
    }

    /*
    //시험출력
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */

    return;
}

int main() {
    int tCase;

    cin>>tCase;

    //dp는 최대로 해서 1번만 호출한다(각 테케마다가 아니라)
    dp.assign(MAX+1, vector<ll>(4,0));
    dpFunc(MAX);

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;

        int ans=((dp[input][1]+dp[input][2])%MOD+dp[input][3])%MOD;
        cout<<ans<<"\n";
    }
    
    return 0;
}