#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    문제 분석

    dp[i]가 의미하는 것
    : i번까지 마신 가장 많은 양의 포도주

    이때,
    연속 3잔의 와인을 마시는 것은 불가능

    점화식은 두 가지 경우로 나누어진다.
    1) 이전 인덱스가 바로 이전 인덱스 값을 사용했을 경우
    -> 그럼 현 인덱스는 이전 인덱스를 더할 수 없음

    2) 이전 인덱스가 바로 이전 인덱스 값을 사용하지 않았을 경우
    -> 그럼 현 인덱스는 이전 인덱스를 더할 수 있음

    1)의 경우
    dp[i]=max(dp[i-2]+wines[i], wines[i-1]+wines[i])
    왜냐하면 
    dp[i-1]+wines[i]는 불가->연속으로 놓여 있는 3잔 마실 수 없으므로

    따라서 dp[i-2]와 wines[i-1](이전 요소)

    2)의 경우
    dp[i]=max(dp[i-2]+wines[i], dp[i-1]+wines[i])
    이전 dp 누계값을 사용할 수 있음

    1,2둘 다
    wines[i-1], dp[i-1]을 사용했을 경우,
    isContinuous=true로 하여 다음 인덱스는
    1번 케이스로 넘어가서 이전 인덱스 값 사용한 경우로
    처리하도록 한다.    

    위 경우는 실패한 점화식
    반례)
    6
    1 1 0 0 1 1
    처럼 중간에 2개 이상 사용되지 않는 경우
    1 2 1 2 3 3 이렇게 중간값을 건너뛰지 못하고
    앞을 버리는 꼴이 됨
    

    아./.....
    연속으로 3잔 마시는지 여부도 점화식으로 세워야 함
    1) dp[i-1]: 현재 잔을 마시지 않는 경우
    2) dp[i-2]+wines[i]: 현재 잔을 마시고, 이전 잔을 마시지 않는 경우
    3) dp[i-3]+wines[i-1]+wines[i]
    : 현재 잔과 이전 잔을 마시고, 그 이전 잔을 마시지 않는 경우

    이 세 가지 경우 중 최대값을 선택하기 때문에,
    자연스럽게 연속으로 3잔 마시는 경우 배제됨

    6
    1 1 0 0 1 1
    1 2 2 2 3 4
    로, 중간값 잘 건너뛰고 초반값과 후반값 합산됨
    
*/

vector<int> wines;
vector<int> dp;

int memoi(){
    dp[0]=wines[0];
    dp[1]=dp[0]+wines[1];
    dp[2]=max({wines[0]+wines[1], wines[1]+wines[2], wines[0]+wines[2]});

    for(int i=3;i<dp.size();i++){
        dp[i]= max({dp[i-1], dp[i-2]+wines[i], dp[i-3]+wines[i-1]+wines[i]});
        
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int tCase;
    cin>>tCase;

    wines.resize(tCase);
    dp.resize(tCase);
    
    for(int i=0;i<tCase;i++){
        cin>>wines[i];
    }

    int result = memoi();

    /*
    for(auto it: dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    cout<<result<<endl;
    
    
    return 0;
}