#include <iostream>
#include <vector>
using namespace std;

vector<long long int> dp;

long long int tabulation(int n){
    if(n==1||n==2||n==3){
        return 1;
    }

    dp[1]=1, dp[2]=1, dp[3]=1;

    for(int i=4;i<n+1;i++){
        dp[i]=dp[i-3]+dp[i-2];
    }

    return dp[n];

}

int main(void){
    int tCase;
    int input;
    
    dp.resize(100+1);

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        cin>>input; 
        //input은 n번째 삼각형, dp[n]은 n번째 삼각형 변의 길이

        cout<<tabulation(input)<<"\n";
    }
    
    
    return 0;
}