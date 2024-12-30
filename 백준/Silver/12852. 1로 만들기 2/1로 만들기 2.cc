#include <bits/stdc++.h>
#define MAX 987'654'321
using namespace std;

vector<int> dp;
vector<vector<int>> include;

//in: 정수 xo
//out: 연산을 사용하는 횟수의 최솟값
void makeOne(int n){
    dp[0]=0;    
    dp[1]=0;

    for(int i=2;i<=n;i++){
        int div3=n, div2=n;
    
        if(i%3==0){
            div3=i/3;
        }
    
        if(i%2==0){
            div2=i/2;
        }

        /*
        priority_queue<pair<int, int>> values;
        
        values.push({dp[div3], div3});
        values.push({dp[div2], div2});
        values.push({dp[n-3], n-1});
        */

        if(dp[div3]<dp[div2]){
            if(dp[i-1]<dp[div3]){//최소가 dp[n-1]
                include[i]=include[i-1];
                include[i].push_back(i-1);
            }
            else{//최소가 dp[div3]
                include[i]=include[div3];
                include[i].push_back(div3);
            }
        }
        else{//dp[div2]
            if(dp[i-1]<dp[div2]){//최소가 dp[n-1]
                include[i]=include[i-1];
                include[i].push_back(i-1);
            }
            else{//최소가 dp[div2]
                include[i]=include[div2];
                include[i].push_back(div2);
            }
        }
    
        dp[i]=min({dp[div3], dp[div2], dp[i-1]})+1;
    }

    for(int i=0;i<include.size();i++){
        include[i].push_back(i);
        reverse(include[i].begin(), include[i].end());
    }

    
    
    cout<<dp[n]<<"\n";

    for(auto i:include[n]){
        cout<<i<<" ";
    }
    cout<<"\n";
}


int main() {
    int n;
    cin>>n;

    dp.assign(n+1, MAX);
    include.resize(n+1);

    makeOne(n);
    return 0;
}