#include <bits/stdc++.h>

using namespace std;

/*
    풀이법:
    - k까지의 숫자 중 n개를 고르는 모든 경우 출력
    - **이때, 뽑는 수 중복 가능!!**
    - 탈출 조건: n개 다 뽑았을 경우
        해당 쌍 출력하고 리턴
    - 데이터 원복
        현재 push 데이터 pop하기
        visited 다시 미방문 상태 false로

    시간복잡도:
    n<=8이므로 가능!
    백트래킹, 중복 있이 뽑기는 O(n^n)

    자료구조:
    2개 뽑아서 넣는 vector
    해당 숫자 방문 여부 체크 visited vector
*/

int K, N;
vector<int> pick;
vector<int> visited;

void backtracking(int n){
    if(n==N){
        for(auto p:pick){
            cout<<p<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=K;i++){//1~k 중 미방문 상태인 숫자 뽑기
        visited[i]=true;
        pick.push_back(i);

        //한 depth 더 들어가기
        backtracking(n+1);

        //데이터 원복
        visited[i]=false;
        pick.pop_back();
    }

}


int main() {
    cin >> K >> N;

    visited.assign(K+1, false);

    backtracking(0);

    return 0;
}
