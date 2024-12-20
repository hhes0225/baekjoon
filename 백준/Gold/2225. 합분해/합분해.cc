#include <bits/stdc++.h>
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
/*
    dp[n][k]: k개의 수를 사용하여 숫자 n을 만들어내는 총 경우의 수
    - 순서 다른 것 반영, 한 개 수 여러 개 사용 반영

    # 점화식 : 그냥 쭈욱 써보니까 나와서.. 어떤 원리에 의거했다! 는 잘 모르겠음
    - 일단 초기화: k=1(1개 수 사용하여) n 만드는 경우: 무조건 1개(자기자신)\
    - 점화식: dp[n][k]=dp[n-1][k]+dp[n][k-1];

    계속 패턴이 누적되는 것 같긴 했음
    0 0 n, 0 1 n-1, 0 2 n-2 ... 0 n/2 n/2, ...
*/

ll dpFunc(int n, int k){
    //초기화1: k=1(1개 수 사용) n 만드는 경우-> 무조건 1(자기자신)
    for(int i=1;i<=n;i++) dp[i][1]=1;

    //초기화 2: n=1, k개의 수를 사용하여 1 만드는 경우-> 무조건 k개 
    //(001,010,100 같이 배치만 다르게 해주는 경우의 수)
    for(int i=1;i<=k;i++) dp[1][i]=i;

    //점화식 적용
    //최대 200*200=40000회-> O(n^2)?
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
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

    return dp[n][k];
}

int main() {
    int n, k;
    cin>>n>>k;

    dp.assign(n+1, vector<ll>(k+1, 0));

    cout<<dpFunc(n,k)<<"\n";
    return 0;
}