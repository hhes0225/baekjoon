#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

unordered_map<int, int> coins;
vector<int> dp;

/*
    N가지 종류 동전이 있을 때 총 돈의 절반으로 나눌 수 있는가?
== N가지 종류의 동전을 사용해서 x(==y/2)라는 값을 달성할 수 있는가?

    dp[i]: 동전들로 i라는 값을 만들 수 있는가?(true/false)
*/

void dpFunc(int maxVal){
    //초기값
    dp[0]=0;//전부 안내는 경우
    
    // for(auto c:coins){
    //     auto [val, quantity]=c;

    //     for(int i=1;i<=quantity;i++){
    //         dp[val*i]=true;//한 동전으로만 구성된 경우
    //     }
    // }

    for(auto c:coins){
        auto [val, quantity]=c;
        
        for(int i=0;i<=maxVal;i++){
            if(dp[i]>=0) dp[i]=quantity;//이만큼의 동전 쓸 수 있음
            else if(i<val || dp[i-val]<=0){
                dp[i]=-1;//만들기 불가
            }
            else dp[i]=dp[i-val]-1;//동전 하나 써서 만듦->남은 개수 감소       
        }
    }
}

int main() {
    for(int t=0;t<3;t++){
        int n;
        cin>>n;

        // coins.resize(n);

        int total=0;
        for(int i=0;i<n;i++){
            int val,quantity;
            cin>>val>>quantity;
            coins[val]=quantity;
            total+=(val*quantity);//동전으로 만들 수 있는 총합
        }

        if(total%2==1){//총합 홀수면 둘로 나누기 불가
            cout<<0<<"\n";
            continue;
        }

        //--이하 총합이 짝수인 경우--
        dp.assign(total+1, -1);
    
        dpFunc(total);

        if(dp[total/2]>=0) cout<<1<<"\n";
        else cout<<0<<"\n";

        coins.clear();
        dp.clear();
    }
    return 0;
}