#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> stairs;

int dpFunc(int n){
    //시작에서 1계단
    dp[1]=stairs[1];
    //1계단 올라간 상태에서 다시 1계단, 시작에서 바로 2계단
    dp[2]=max(stairs[1]+stairs[2],stairs[2]);

    /*
        점화식
        dp[n]: n번째 계단에 도달하기까지 최대 점수

        2 계단 오르는 경우:
        dp[i-2]+stairs[i]
        (i-2번째 까지의 최대 점수+i번째 계단의 점수)
        
        1 계단 오르는 경우:
        dp[i-3]+stairs[i-1]+stairs[i];
        **연속 세 개의 계단을 오를 수 없으므로**
        i-3번째 까지의 최대 점수+i-1번째 계단 점수+i번째 계단 점수
        그래서 의도적으로 i-2번째 배제해서 연속 3개 계단 기피
    */
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i]);
    }

    /*
    //출력
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
    stairs.assign(n+1, 0);

    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }

    cout<<dpFunc(n)<<"\n";
    
    return 0;
}