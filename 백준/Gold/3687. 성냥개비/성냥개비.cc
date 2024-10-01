#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
/*
    숫자별로 쓰이는 성냥개비 개수
    0: 6개
    1: 2개
    2: 5개
    3: 5개
    4: 4개
    5: 5개
    6: 6개
    7: 3개
    8: 7개
    9: 6개
*/


int matches_min[9]={0,0,1,7,4,2,0,8,10};
//0~8개의 성냥으로 만들 수 있는 최소값
vector<long long> dpTable;
//i개의 성냥으로 만들 수 있는 가장 작은 한 자리수

void makeMin(int num){
    for(int i=1;i<9;i++){
        dpTable[i]=matches_min[i];
    }

    dpTable[6]=6;//0대신 6

    for(int i=9;i<101;i++){
        for(int j=2; j<8; j++){
            dpTable[i] = min(dpTable[i], dpTable[i-j]*10 + matches_min[j]);
        }
    }
}

/*
    가장 큰 수: 자리수가 가장 길면서 숫자가 큰 수
    숫자 길이: 성냥개비 2개가 최소이므로 2로 나누기
    n/2한 몫을 자리수 길이로.

    if 홀수면? 첫번째 수는 7(3개), 나머지는 1(2개)로
    else(짝수) 모든 수를 1(2개)로
    
*/
string makeMax(int num){
    int len = num/2;
    string result = "";
    
    for(int i=0;i<len;i++){
        result +="1";    
    }

    if(num%2!=0){
        result[0]='7';
    }

    return result;
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int num;
        cin>>num;

        dpTable.assign(100+1, LLONG_MAX);

        makeMin(num);
        cout<<dpTable[num]<<" ";

        //성냥개비로 최대값 만들기
        cout<<makeMax(num)<<"\n";
    }
    
    return 0;
}