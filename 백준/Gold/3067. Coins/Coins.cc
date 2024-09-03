#include <iostream>
#include <vector>
#include <algorithm>
#define LIMIT 10001
using namespace std;

vector<long long int> dp;

/*
    문제 분석:
    2가지, 1원 2원 화폐로, 1000원 만들 수 있는 경우의 수

    dp[i]가 의미하는 것:
    금액 i원을 만드는 방법의 경우의 수

    15988: 1,2,3 더하기 3(실버 2였나) 그 문제랑 비슷하지만
    사용자가 1,2,3 대신 숫자를 정한다는 점이 다르다.

    1,2,3 더하기때 [i-1]+[i-2]+[i-3]으로 풀었으므로
    유사하게 화폐 단위 배열을 순회하여
    for(i)//dp 배열 순회
        for(j)//화폐 단위 배열 순회
            //i-j가 주어진 dp 배열 범위 이내라면
            dp[i]+=dp[i-cur[j]];
    -> 동전 순서에 달라지는 경우도 전부 셈
    1원 5원 1원 / 5원 1원 1원 -> 다른 경우의 수로 카운트

    혹은
    for(i)//화폐 단위 배열 순회
        for(cur[i]~j~limit)//dp 배열 순회
            dp[i]+=dp[i-cur[j]];
    -> 동전 순서 달라져도 개수만 같다면 같은 경우의 수로 봄
    1원 5원 1원 / 5원 1원 1원 -> 같은 경우의 수

    이런 식으로 점화식 하면 될 듯
    cur[j] 전 인덱스에서 특정 cur[j] 화폐를 더해준 게 dp[i]이므로
*/

void memoi(vector<int>& currency, int goal){
    fill(dp.begin(), dp.end(), 0);
    //0원일 때에는 동전을 아예 두지 않는 1가지 경우가 있으므로 dp[0]=1;
    dp[0]=1;

    for(auto cur:currency){
        for(int i=cur;i<=goal;i++){
            dp[i]+=dp[i-cur];
        }
    }
}

int main() {
    int tCase;
    vector<int> currency;
    
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        dp.assign(LIMIT, 0);
        int curTypes;
        cin>>curTypes;

        for(int j=0;j<curTypes; j++){
            int curs;
            cin>>curs;
            currency.push_back(curs);
        }

        int goal;
        cin>>goal;

        memoi(currency, goal);

        cout<<dp[goal]<<"\n";

        currency.clear();
    }
    
    return 0;
}
