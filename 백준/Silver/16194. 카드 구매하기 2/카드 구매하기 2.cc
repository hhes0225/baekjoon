#include <bits/stdc++.h>
#define MAX 987'654'321
using namespace std;

vector<int> cards;
vector<int> dp;
//dp[i]: 카드 i장 샀을 때 최소 가격
/*
    점화식
    dp[1]=arr[1]
    dp[2]=min(dp[1]+arr[1], dp[0]+arr[2])
    dp[3]=min(dp[2]+arr[1], dp[1]+arr[2], dp[0]+arr[3])
    dp[4]=min(dp[3]+arr[1], dp[2]+arr[2], dp[1]+arr[3], dp[0]+arr[4])
    ...
    이 규칙성을 기반으로 코드를 작성했음.
    dp[n]=min(dp[n-1]+arr[1], dp[n-2]+arr[2], ... dp[1]+arr[n-1], dp[0]+arr[n])
*/

int minCardCost(int n){
    dp[0]=0;//카드 0장 살 때는 0원 필요

    for(int i=1;i<=n;i++){//dp 배열 순회
        //cout<<i<<"\n";
        for(int j=0;j<i;j++){//cards 배열 순회
            //cout<<j<<" "<<i-j<<": ";
            //cout<<dp[j]+cards[i-j]<<"\n";
            dp[i]=min(dp[i], dp[j]+cards[i-j]);
        }
    }

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    
    cout<<"\n";*/

    return dp[n];
    
}

int main() {
    int n;
    cin>>n;

    cards.resize(n+1);
    dp.assign(n+1, MAX);

    for(int i=1;i<=n;i++){
        cin>>cards[i];
    }

    cout<<minCardCost(n)<<"\n";
    return 0;
}