#include <bits/stdc++.h>
#define MAX 987'654'321
using namespace std;

vector<int> board;
vector<int> dp;

int jumpBoard(int n){
    dp[0]=0;
    //if(board[0]!=0)
    //    dp[board[0]]=1;

    for(int i=0;i<n-1;i++){//점프 칸 순회
        //cout<<i<<" "<<board[i]<<"\n";
        
        for(int j=1;j<=board[i];j++){
            if(i+j>=n){
                break;
            }
            else{
                dp[i+j]=min(dp[i+j], dp[i]+1);
            }
        }
    }

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    if(dp[n-1]==MAX){
        dp[n-1]=-1;
    }
    
    return dp[n-1];
}

int main() {
    int n;
    cin>>n;

    board.resize(n);
    dp.assign(n, MAX);

    for(int i=0;i<n;i++){
        cin>>board[i];
    }

    cout<<jumpBoard(n)<<"\n";
    
    return 0;
}