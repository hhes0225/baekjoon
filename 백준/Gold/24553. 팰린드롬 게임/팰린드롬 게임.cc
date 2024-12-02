#include <bits/stdc++.h>
using namespace std;

/*
    https://bluesparrow.tistory.com/9

    처음: dp 는 아닌거같았음. 10^18 순회만 생각하고 있어서. 따라서 시뮬레이션으로 접근
    (이전에 돌 게임 유형 풀어보기는 했는데 쉬운 문제여서 dp 사용 안했었음)
    남은 돌의 범위 내의 최대 팰린드롬 수 생성해서 빼는 식
    - 최대 팰린드롬 수 생성법: 숫자의 절반 앞부분을 reverse
        :123/456 -> 123/321
    - 만약 팰린드롬 수가 원래 수보다 더 큰 경우-> 절반 앞부분 수-1 후 reverse
        :987/654 -> 987789(x) / 986689(o)

    근데 이렇게 했더니 최선의 경우가 나오지 않음

    그래서 위 참고자료를 봤더니 일정한 규칙이 있었음
    [당연한 규칙]
    - 돌 < 10 : 상윤 승(한 자리 수 == 팰린드롬 수)
    - 돌 == 팰린드롬 수: 상윤 승(선인 상윤이 한번에 가져가면 끝)

    [일정한 규칙]
    - n1~n9 : 상윤 승
    - n0: 승우 승
    (한 30까지 직접 쓰면서 보니 이러한 규칙이 세워졌음)

    따라서 필요한 기능
    - 팰린드롬 수인지 확인하는 기능
    - 당연한 규칙 + 일정한 규칙에 따라 판별하는 기능
*/

bool isPal(long long n){
    string numToStr=to_string(n);

    for(int i=0;i<numToStr.size()/2;i++){
        if(numToStr[i]!=numToStr[numToStr.size()-i-1]){
            return false;
        }
    }

    return true;
}

void findWinner(long long n){
    //0 is 상윤, 1 is 승우
    if(n<10 || isPal(n)){
        cout<<"0\n";
    }
    else{
        if(n%10==0){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
    
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        long long stone;
        cin>>stone;
        findWinner(stone);
    }
    
    return 0;
}