#include <bits/stdc++.h>
#define FOR(i, n) for(int i=0;i<n;i++)

#define R 0
#define G 1
#define B 2

using namespace std;

int n;
vector<vector<int>> colorCost;
vector<vector<int>> dp;
//dp[i][color]: i번째 집을 color로 칠할 때 최소 비용

int dpFunc(){
    dp[0][R]=colorCost[0][R];
    dp[0][G]=colorCost[0][G];
    dp[0][B]=colorCost[0][B];

    for(int i=1;i<n;i++){
        dp[i][R]=colorCost[i][R]+min(dp[i-1][G], dp[i-1][B]);
        dp[i][G]=colorCost[i][G]+min(dp[i-1][R], dp[i-1][B]);
        dp[i][B]=colorCost[i][B]+min(dp[i-1][G], dp[i-1][R]);
    }

    return min({dp[n-1][R], dp[n-1][G], dp[n-1][B]});
}


/*
잘못된 방식.. 1차원 dp
int dpFunc(int initColor){
    fill(dp.begin(), dp.end(), 0);
    
    //이전 집  색 저장
    int prevColor=initColor;
    //첫 번째 집 칠하기
    dp[0]=colorCost[0][initColor];

    
    for(int i=1;i<n;i++){
        if(prevColor==R){
            if(colorCost[i][G]<colorCost[i][B]){
                prevColor=G;
            }
            else{
                prevColor=B;
            }
            
            dp[i]=dp[i-1]+min(colorCost[i][G], colorCost[i][B]);
        }
        else if(prevColor==G){
            if(colorCost[i][R]<colorCost[i][B]){
                prevColor=R;
            }
            else{
                prevColor=B;
            }
            
            dp[i]=dp[i-1]+min(colorCost[i][R], colorCost[i][B]);
        }
        else{//initColor==B
            if(colorCost[i][G]<colorCost[i][R]){
                prevColor=G;
            }
            else{
                prevColor=R;
            }
            
            dp[i]=dp[i-1]+min(colorCost[i][G], colorCost[i][R]);
        }
    }
    

    for(int it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";

    return dp[n-1];
}

*/

int main() {

    cin>>n;

    colorCost.resize(n, vector<int>(3));
    dp.resize(n, vector<int>(3));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>colorCost[i][j];
        }
    }

    int result=dpFunc();

    cout<<result<<"\n";
    
    
    return 0;
}