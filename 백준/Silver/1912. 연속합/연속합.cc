#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    이건 누적합 문제가 아니라 dp임을 상기할 것.
    dp[i]=이 인덱스까지 연속 부분 수열의 최대 합
    max(input[i], dp[i-1]+input[i])
    
    이렇게 하면 음수일 때 처리할 필요 없이
    이전dp보다 현재input이 크면 현재input으로 대체,
    현재input이 작으면 이전dp+현재input으로 누적해주기

    나는 왜 뻘짓을 하였는가...
*/

vector<int> signedNum;
vector<int> input;

int dp(){
    signedNum[0]=input[0];
    
    for(int i=1;i<input.size();i++){
        signedNum[i]=max(input[i], signedNum[i-1]+input[i]);

        /*
        for(auto it : signedNum){
            cout<<it<<" ";
        }
        cout<<endl;*/
    }


    return *max_element(signedNum.begin(), signedNum.end());
}

int main() {
    int tCase;

    cin>>tCase;

    input.resize(tCase);
    signedNum.assign(tCase, 0);

    for(int i=0;i<tCase;i++){
        cin>>input[i];
    }


    int result = dp();

    /*
    for(auto it : signedNum){
        cout<<it<<" ";
    }
    cout<<endl;
    */
    
    cout<<result<<endl;
    
    return 0;
}