#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

/*
    설명 잘 이해가 안가면 그래프로 그려볼 것
    - 가로 2칸이 정해져있음
    - 사자 한 마리도 배치하지 않는 경우도 하나의 경우의 수
    - 케이지에 사자가 있는 경우 주변 1칸 십자는 사자 못넣음
    - 따라서 마지막 행에 들어갈 수 있는 사자의 경우의 수는
        | o  x |, | x  o |, | x  x | 세 가지
        
    dp[i][3]: i가 마지막 행일 때, 위 세 가지에 해당하는 경우의 수

    dp[i-1][o x]-> 그 다음 행에는 x o , x x 만 가능
    dp[i-1][x o]-> 그 다음 행에는 o x , x x 만 가능
    dp[i-1][x x]-> 그 다음 행에는 o x, x o , x x 전부 가능

    따라서 점화식은
    dp[i][o x] = dp[i-1][x o] + dp[i-1][x x]
    dp[i][x o] = dp[i-1][o x] + dp[i-1][x x]
    dp[i][x x] = dp[i-1][o x] + dp[i-1][x o] + dp[i-1][x x]
*/

vector<vector<int>> dp;

int CageCaseCount(int n){
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;

    for(int i=1;i<n;i++){
        dp[i][0]=(dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
    }

    /*
    //dp 테이블 출력
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */

    return (dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%MOD;
}

int main() {
    int n;
    cin>>n;

    dp.assign(n, vector<int>(3, 0));

    cout<<CageCaseCount(n)<<"\n";
    
    return 0;
}