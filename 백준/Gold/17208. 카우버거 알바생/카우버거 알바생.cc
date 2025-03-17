#include <bits/stdc++.h>
using namespace std;

/*
    한정된 capacity 내의 최대 cost-> 냅색  

    dp[i][burger][fries]
    i번째 주문까지 처리했을 때,
    버거 최대재고 burger와 감튀 최대재고 fries를 처리했을 때 
    최대 주문 처리 수

    현재 주문이 burger보다 적고 fries보다 적으면 주문 처리
    그렇지 않으면 주문 처리 X

    시간복잡도: O(n^3)..?
    최대 주문 수=100 
    최대 버거 수=300
    최대 감튀 수=300
    100*300*300 = 9'000'000
    
*/

vector<pair<int, int>> orders;
vector<vector<vector<int>>> dp;
//dp[i][burger][fries]
//i번째 주문까지 처리했을 때
//버거 최대재고 burger와 감튀 최대재고 fries를 처리했을 때 
//최대 주문 처리 수

int getMaxOrder(int n, int m, int k){
    for(int o=1;o<=n;o++){
        auto [b, f]=orders[o];

        for(int i=1;i<=m;i++){
            if(i-b<0){
                for(int j=1;j<=k;j++){
                    dp[o][i][j]=dp[o-1][i][j];
                }
                continue;
            }
            //현재 버거 재고로 버거 처리 불가능하면 패스
            
            for(int j=1;j<=k;j++){
                if(i-b>=0 && j-f>=0){
                    //cout<<o<<"번째 주문 처리!\n";
                    dp[o][i][j]=max(dp[o-1][i][j], dp[o-1][i-b][j-f]+1);
                }
                else{
                    dp[o][i][j]=dp[o-1][i][j];
                }
            }
        }
    }

    return dp[n][m][k];
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;

    orders.resize(n+1);
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));

    for(int i=1;i<=n;i++){
        cin>>orders[i].first>>orders[i].second;
    }

    cout<<getMaxOrder(n, m, k)<<"\n";
    
    return 0;
}