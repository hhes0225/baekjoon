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

void backtracking(int prev, int depth, int count){
    bool isBeautiful=true;
    
    if(depth==n){
        // for(int i=1;i<10;i++){
        //     if(continuous[i]%i!=0){
        //         isBeautiful=false;
        //         break;
        //     }
        // }

        if(count%prev==0) {
            ans++;
        }
        return;
    }

    for(int i=1;i<10;i++){
        // int keepPrevVal=continuous[prev];
        // int keepCurVal=continuous[i];//백트래킹 원복용

        // if(prev==i) continuous[i]++;
        // else {
        //     //continuous[prev]=1;
        //     continuous[i]++;
        // }

        // //백트래킹
        // backtracking(i, depth+1);

        // //백트래킹 데이터 원복
        // continuous[prev]=keepPrevVal;
        // continuous[i]=keepCurVal;

        if(depth==0) backtracking(depth+1, i, 1);
        else{
            if(i==prev) backtracking(depth+1, i, count+1);
            else if(count%prev==0) backtracking(depth+1, i, 1);
        }
    }
    
    return;
}

int main() {
    cin >> n;
    continuous.assign(10, 0);

    continuous[0]=0;//아름다운 수 되려면 0은 0번 나와야 함
    
    backtracking(0,0, 0);

    cout<<ans<<"\n";

    return 0;
}
