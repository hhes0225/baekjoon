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
vector<int> num;
long long ans=0;

bool isBeautiful(){
    for(int i=0;i<n;i+=num[i]){
        //연속하여 해당 숫자만큼 나올 수 없는 경우
        if(i+num[i]-1>=n) return false;

        for(int j=i;j<i+num[i];j++){
            if(num[j]!=num[i]) return false;//해당 구간 내에서 연속하지 않는 경우
        }
    }

    return true;
}

void backtracking(int depth){
    if(depth==n){
        if(isBeautiful()) ans++;
        return;
    }

    for(int d=1;d<=4;d++){
        num.push_back(d);

        backtracking(depth+1);

        num.pop_back();
    }
    
    return;
}

int main() {
    cin >> n;
    
    backtracking(0);

    cout<<ans<<"\n";

    return 0;
}
