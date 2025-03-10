#include <bits/stdc++.h>

using namespace std;

/*
    풀이과정
    - n자리 아름다운 수 구하기
    - 자릿수 1개 늘어날 때마다 재귀 depth 1단계 깊어짐
    - 탈출조건: 현재 들어온 수가 n자리이라면 return
        현재 아름다운 수라고 탈출하면 안됨. 1도 아름다운 수지만 111도 아름다운 수이기 때문
    - 현재 아름다운 수라면 ans++
    - 데이터 원복  
        continuous 초기화


    시간복잡도
    n<=10이므로 가능

    자료구조
    int형 continuous 벡터(현재 수 중 연속되는 숫자 개수 세기)
    visited는 필요 없을 듯.(중복 제거할 필요 없이 111, 121 다 가능)

*/


int n;
vector<int> continuous;
int ans=0;

void backtracking(int prev, int depth){
    bool isBeautiful=true;

    // for(auto c:continuous){
    //     cout<<c<<" ";
    // }
    // cout<<"\n";

    if(prev==0||depth!=n){
        isBeautiful=false;
    }
    
    if(depth==n){
        for(int i=1;i<10;i++){
            if(continuous[i]%i!=0){
                //cout<<"연속되지 않음: "<<i<<", "<<continuous[i]<<"\n";
                isBeautiful=false;
                break;
            }
        }

        if(isBeautiful) {
            ans++;
        }
        return;
    }

    for(int i=1;i<10;i++){
        int keepCurVal=continuous[i];//백트래킹 원복용

        if(prev==i) continuous[i]++;
        else continuous[i]=1;

        //백트래킹
        backtracking(i, depth+1);
        //cout<<"pop!\n";

        //백트래킹 데이터 원복
        continuous[i]=keepCurVal;
    }
    
    return;
}

int main() {
    cin >> n;
    continuous.assign(10, 0);

    continuous[0]=1;//아름다운 수 되려면 0은 0번 나와야 함
    
    backtracking(0,0);

    cout<<ans<<"\n";

    return 0;
}
