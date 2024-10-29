#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
vector<vector<int>> input;
vector<vector<int>> dp;
int maxVal;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dpFunc(){
    dp[0][0] = input[0][0];
    dp[1][0] = input[1][0];

    if(len >= 2){
        dp[0][1] = dp[1][0] + input[0][1];
        dp[1][1] = dp[0][0] + input[1][1];
    }

    for(int i = 2; i < len; i++){
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + input[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + input[1][i];
    }

    maxVal = max(dp[0][len - 1], dp[1][len - 1]);
    cout << maxVal << endl;
}

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        cin>>len;

        input.assign(2, vector<int>(len, 0));
        dp.assign(2, vector<int>(len, 0));

        for(int i=0;i<2;i++){
            for(int j=0;j<len;j++){
                cin>>input[i][j];
            }
        }
        maxVal=0;

        dpFunc();
    }

    
    
    return 0;
}