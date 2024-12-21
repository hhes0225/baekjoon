#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> candy;
/*
    dp[i][j]: (i, j)칸까지 도달했을 때 가져올 수 있는 사탕 최대값

    점화식
    **이동 방향은 오른쪽, 아래, 오른쪽 아래 대각선**
    -> 따라서 왼쪽, 위쪽으로 되돌아갈 수 없음! 앞으로 나갈 뿐..

    (1, 1): 현재 위치. candy[i][j]
    제일 왼쪽 라인들-> 이전 칸에서 아래쪽으로 가는 방법밖에 도달방법이 없음.
    : dp[i][j]=dp[i-1][j]+candy[i][j]
    제일 위 라인들 -> 이전 칸에서 오른쪽으로 가야지만 도달 가능
    : dp[i][j]=dp[i][j-1]+candy[i][j];

    나머지 칸들: 오, 아, 오아대각선 세 경우 전부 고려
    dp[i][j]=max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+candy[i][j]
*/

int dpFunc(int n, int m){
    //초기화: 준규의 현재 위치 (1, 1)
    dp[0][0]=candy[0][0];

    //제일 왼쪽 라인들
    for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+candy[i][0];

    //제일 위쪽 라인들
    for(int i=1;i<m;i++) dp[0][i]=dp[0][i-1]+candy[0][i];

    //나머지 칸들
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+candy[i][j];
        }
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

    return dp[n-1][m-1];
    
}

int main() {
    int n, m;
    cin>>n>>m;

    dp.assign(n, vector<int>(m, 0));
    candy.resize(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>candy[i][j];
        }
    }

    cout<<dpFunc(n, m)<<"\n";

    
    return 0;
}