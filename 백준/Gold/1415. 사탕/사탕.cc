#include <bits/stdc++.h>
using namespace std;
const int MAX = 10'000;
typedef long long ll;

vector<bool> isPrime;
unordered_map<int, int> candyDict;
vector<ll> dp;
int zeroCandyCnt=1;
//dp[i]: 가격 합이 i인 사탕을 사는 방법의 수


void GetPrimes(int n){
    isPrime[0]=isPrime[1]=false;
    
    //에라토스테네스의 체
    for(int i=2;i<=n*MAX;i++){
        for(int j=i+i;j<=n*MAX;j+=i){
            isPrime[j]=false;
        }
    }
}

int main() {
    int n;
    ll ans=0;

    cin>>n;

    isPrime.assign(n*MAX+1, true);
    dp.assign(n*MAX+1, 0);
    GetPrimes(n);

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp==0) zeroCandyCnt++;
        else candyDict[tmp]++;
    }

    //초기화
    dp[0]=1;
    
    for(auto candy:candyDict){
        auto [price, count]=candy;

        //dp 배열 뒤에서부터 갱신: 
        //작은 것부터 누적하면 합의 중복이 쌓이므로, 큰 것부터 누적해서 중복 제거
        for(int j=n*MAX;j>=0;j--){
            //같은 가격의 사탕이 여러 개일 때, 사탕 개수별로 누적
            for(int k=1;k<=count;k++){
                if(j-k*price>=0){
                    dp[j]+=dp[j-k*price]; 
                }
            }
        }
    }

    /*
    // dp배열 출력
    for(auto d:dp){
        cout<<d<<" ";
    }
    cout<<"\n";
    */
    
    for(int i=2;i<=n*MAX;i++){
        if(isPrime[i]){
            ans+=dp[i];
        }
    }

    cout<<ans*zeroCandyCnt<<"\n";
    
    return 0;
}