#include <bits/stdc++.h>
using namespace std;
const int MAX = 1121;
const int MAXSPLIT=15;
typedef long long ll;

/*
    자체 태그맞추기
    소수 -> 에라토스테네스의 체
    소수로 합을 구성하는 경우의 수 -> dp
*/

vector<vector<ll>> dp;
//dp[i][k] == i일 때, 서로 다른 소수의 k개의 합 경우의 수

vector<bool> nums;//0~1121의 소수 여부 저장
vector<int> primes;//소수인 수만 저장

void getPrime(){
    //에라토스테네스의 체로 소수 구하기
    for(int i=2;i<MAX;i++){
        for(int j=i+i;j<MAX;j+=i){
            if(!nums[j]){
                continue;
            }
            nums[j]=false;
        }
    }

    for(int i=2;i<MAX;i++){
        if(nums[i]){
            primes.push_back(i);
        }
    }
    //cout<<primes.size()<<"\n";
    //1121->소수만 187개

    /*
    for(auto p:primes){
        cout<<p<<" ";
    }
    cout<<"\n";
    */
}

void getPrimeSumCase(){
        
    for(auto p:primes){
        for(int i=MAX-1;i>=0;i--){
            if(i<p) continue;
            if(i==p){
                dp[p][1]=1;
                continue;
            }
            for(int j=2;j<MAXSPLIT;j++){    
                dp[i][j]+=dp[i-p][j-1];
            }
        }
    }
    
    /*
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    */
    
}

int main() {
    int tCase;
    cin>>tCase;

    nums.assign(MAX, true);
    dp.assign(MAX, vector<ll>(MAXSPLIT, 0));

    getPrime();
    getPrimeSumCase();

    for(int i=0;i<tCase;i++){
        int n, k;
        cin>>n>>k;

        cout<<dp[n][k]<<"\n";
    }

    
    
    return 0;
}