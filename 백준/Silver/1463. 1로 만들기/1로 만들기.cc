#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;



int tabulation(int n){
    if(n==1){
        return 0;
    }
    else if(n==2 || n==3){
        return 1;
    }
    
    dp[1]=0, dp[2]=1, dp[3]=1;

    for(int i=4;i<=n; i++){
        //모든 수는 기본적으로 case 3에 해당: 1을 빼기
        dp[i]=dp[i-1]+1;
        
        //여기서 3으로 나누어 떨어진다면, 그리고 나누었을 때 케이스가 더 작으면 값 변경
        if(i%3==0){
            dp[i]=min(dp[i], dp[i/3]+1);
        }
        //여기서 2으로 나누어 떨어진다면, 그리고 나누었을 때 케이스가 더 작으면 값 변경
        if(i%2==0){
            dp[i]=min(dp[i], dp[i/2]+1);
        }
        
    }
    
    return dp[n];
}

int main(void){
    dp.resize(1000000+1);
    int input;
    cin>>input;

    cout<<tabulation(input)<<"\n";
    

    return 0;
}