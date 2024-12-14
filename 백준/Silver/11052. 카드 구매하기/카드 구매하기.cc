#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> cards;

int dpFunc(int n){
    //카드 1장만 사기 위해서는 무조건 1장짜리 팩 사야함
    dp[1]=cards[1];

    /*
        점화식
        dp[n] = 카드 n장을 사기 위한 최대 가격

        n장 카드 사기 위해 다음과 같은 조합 고려했다.
        n장짜리 1팩
        n-1장 1팩, 1장짜리 1팩
        n-2장 1팩, 2장짜리 1팩
        ...

        이렇게 하면 최대의 가격이 나오게 할 수 있다.
        (n-3)+1+2 이런거 고려 안해도 되는게
        이미 dp[3]일때 0-3, 1-2 등등 다 고려된 것이므로
        2개의 dp테이블에 저장된 데이터만 보면 된다.

        입력이 1,000이므로 O(n^2)으로 풀어도 괜찮을 것 같았음.
        최대 1,000,000회 돌아가니까.
    */
    for(int i=1;i<=n;i++){
        dp[i]=cards[i];
        for(int j=i-1;j>=1;j--){
            dp[i]=max(dp[i], dp[j]+cards[i-j]);
        }
    }

    /*
    //출력하기
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    
    dp.assign(n+1, 0);
    cards.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>cards[i];
    }

    cout<<dpFunc(n)<<"\n";
    
    
    return 0;
}