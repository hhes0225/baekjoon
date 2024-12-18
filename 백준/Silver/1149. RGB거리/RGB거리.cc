#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
/*
    dp[i][j]: i번 집이 j 색을 칠했을 경우 비용의 최소값
    따라서 다음 집을 보지 않고 이전 집을 본다.
    이전 집에서 내가 선택한 집의 색이 아닌 다른 색을 칠한 경우들을 보고, 최소값 채택

    설정한 점화식:
    dp[i][내가 선택한 색]=min(dp[i-1][안선택한 색1], dp[i-1][안선택한 색2])+house[i][선택한 색];
*/

int dpFunc(const vector<vector<int>> &house, int n){
    //init
    for(int i=0;i<3;i++) dp[1][i]=house[1][i];

    for(int i=2;i<=n;i++){
        //r 선택한 경우
        dp[i][0]=house[i][0]+min(dp[i-1][1], dp[i-1][2]);
        
        //g 선택한 경우
        dp[i][1]=house[i][1]+min(dp[i-1][0], dp[i-1][2]);

        //b 선택한 경우
        dp[i][2]=house[i][2]+min(dp[i-1][0], dp[i-1][1]);
    }

    /*
    //출력
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */

    return *min_element(dp[n].begin(), dp[n].end());
}

int main() {
    int n;
    vector<vector<int>> house;
    
    cin>>n;

    dp.assign(n+1, vector<int>(3, 0));
    house.assign(n+1, vector<int>(3,0));

    for(int i=1;i<=n;i++){
        cin>>house[i][0];//r
        cin>>house[i][1];//g
        cin>>house[i][2];//b
    }

    cout<<dpFunc(house, n)<<"\n";
    
    return 0;
}