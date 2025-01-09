#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> board;
vector<vector<ll>> dp;
int n;

void getRoutes(int i, int j){
    /*시간초과
    if(i==n-1 && j==n-1){
        return;
    }

    int val=board[i][j];
    if(i+val<n){
        dp[i+val][j]+=dp[i][j];
        getRoutes(i+val, j);
    }
    if(j+val<n){
        dp[i][j+val]+=dp[i][j];
        getRoutes(i, j+val);
    }
    */

    dp[i][j]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val=board[i][j];

            if(dp[i][j]==0){continue;}
            if(val==0) continue;

            if(i+val<n){
                dp[i+val][j]+=dp[i][j];
            }
            if(j+val<n){
                dp[i][j+val]+=dp[i][j];
            }

            /*
            cout<<"case: "<<i<<", "<<j<<"\n";
            //dp 테이블 출력
            for(auto i:dp){
                for(auto j:i){
                    cout<<j<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
            */
        }

        
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    board.resize(n, vector<int>(n));
    dp.assign(n, vector<ll>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    //dp[0][0]=1;
    getRoutes(0,0);

    
    


    cout<<dp[n-1][n-1]<<"\n";
    
    return 0;
}