#include <bits/stdc++.h>
using namespace std;

/*
i개 비트 중 j개에 1을 채워 넣어야 함
맨 끝 비트가 1인 경우: 나머지 i-1칸 중 j-1개의 1를 채우면 됨
맨 끝 비트가 0인 경우: 나머지 i-1칸 중 j개의 1을 채워야 함

1. 사전 작업 - dp 배열 만들기
dp[i][j]: i개의 자리가 남았을 때 j개의 1을 사용하는 경우의 수(iCj)
(i<32, j<32)

2. dp 배열 기준으로 판단
*/
typedef long long ll;

constexpr int len=32;
vector<vector<ll>> dp;

void fillDP(){
    dp.assign(len, vector<ll>(len, 0));
    
    dp[0][0]=1;
    
    for(int i=1;i<len;i++){
        dp[i][0]=1;//1을 0개 사용하는 경우의 수(0만 사용하는 경우) 1가지
        
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
}

int main()
{
    int n, l;
    ll i;
    
    cin>>n>>l>>i;
    
    fillDP();
    
    while(n>0){//MSB부터 LSB로 순회
        //1) 판단 기준: n번째 자리에 0을 놓는다면 만들 수 있는 경우의 수?
        //n-1개 중 1을 0개 뽑는 경우+...+L개 뽑는 경우
        ll cnt=0;
        for(int k=0;k<=l;k++){
            cnt+=dp[n-1][k];
        }
        
        //2) 찾는 순서가 범위 안에 있는지 판단
        if(i<=cnt){//찾는 순서가 범위 내 있음
            cout<<0;
        }
        else{//찾는 순서가 범위를 넘어감-> n번째 자리에는 0이 들어갈 수 없음, 1이 들어가야 함
            cout<<1;
            
            i=i-cnt;//1)의 경우의 수 소모
            l--;//사용 가능한 1의 개수 감소
        }
        
        n--;//자릿수 감소
    }

    return 0;
}