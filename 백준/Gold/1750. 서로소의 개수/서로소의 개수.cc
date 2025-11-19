#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10000003;
constexpr int MAXLEN=100001;


/*
    기존에 만들어둔 GCD가 g인 집합들에 새로운 수 num을 추가하면, 
    GCD가 gcd(g, num)인 새로운 집합들이 탄생
    dp_new[gcd(g, X)] += dp_old[g]
    
*/
vector<int> dp;
void GetCoprime(vector<int>& s){
    dp.assign(MAXLEN, 0);
    
    vector<int> nextDP;
    
    //1- 새로운 수 s[i]를 하나씩 처리리
    for(int i=0;i<s.size();i++){

        nextDP=dp;
        
        //2- 기존 GCD들을 순회하며 s[i]와 결합
        for(int j=1;j<MAXLEN;j++){
            if(dp[j]!=0){
                //기존 집합+s[i] 결합
                int newGCD=gcd(s[i],j);
                nextDP[newGCD]= (nextDP[newGCD]+dp[j])%MOD;
            }
        }
        
        //숫자 S[i] 하나만 포함하는 부분집합 +1 해주기
        nextDP[s[i]]=(nextDP[s[i]]+1)%MOD;
        dp=nextDP;//상태 업데이트트
    }
    
}

int main()
{
    int n;
    vector<int> arr;
    
    cin>>n;
    
    arr.resize(n);
    
    for(auto& a:arr){
        cin>>a;
    }
    
    GetCoprime(arr);
    
    cout<<dp[1];

    return 0;
}