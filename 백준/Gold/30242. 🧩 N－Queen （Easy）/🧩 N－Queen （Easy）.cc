#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

int N;
int row;  // 가로 (놓을 수 있는곳이 1)
ll lx, rx;  // 왼대각선, 오른대각선 (놓을 수 없는곳이 1)
int Q[30];
int step[30];
int ans[30];

bool backtracking(int level){
    if(level>N){
        return true;
    }

    // bit : 현재 단계(세로줄)에서 놓을 수 있는 row는 1, 놓을 수 앖는 row는 0
    ll bit = row & ~((lx >> level) | (rx >> (N-level)));

    // 최하위 비트부터 없애면서 모든 비트가 없어질때까지 하나씩 재귀
    for(ll a=0; bit!=0; bit ^= a){

        a = bit & (-bit);  // bit의 최하위 비트

        // a자리에 놓았을 경우
        row ^= a;
        lx ^= a << level;
        rx ^= a << (N-level);

        // step을 활용해 구해야할 다음 단계로 바로 접근
        if(backtracking(level + step[level])) {
            ans[level] = a;
            return true;
        }

        // 백트래킹
        row ^= a;
        lx ^= a << level; 
        rx ^= a << (N-level);
    } 
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    row = (1 << N) - 1;
    N--;

    for(int i = 0; i <= N; i++) {
        cin >> Q[i];
    }

    for(int i = 0; i <= N; i++){
        // 이미 놓여진 말 체크해주기
        if(Q[i]){
            // 1ull = 1을 그냥 쓰면 부호있는 32비트 상수이므로 64비트 연산시 이상한 값이 나올 수 있다.
            ans[i] = 1 << (Q[i]-1);
            row ^= 1ull << (Q[i] - 1);  // 놓을 수 있는 곳이 1
            lx |= 1ull << (Q[i] - 1 + i);  // 놓을 수 없는 곳이 1
            rx |= 1ull << (Q[i] - 1 + N - i);  // 놓을 수 없는 곳이 1
        }

        // 0이라면 다음에 구해야 할 곳이 몇 스텝 후인지 미리 계산
        else {
            int s = 1;
            while(i + s <= N && Q[i+s]) ++s;
            step[i] = s;
        }
    }

    // backtracking 시작지점 찾기
    int start = 0;
    while(start <= N && Q[start]) ++start;

    // 해가 없음
    if(!backtracking(start)){
        cout << -1; 
        return 0;
    }

    // 기록된 i번째 비트답을 이용해 답 출력
    for(int i = 0; i <= N; i++){
        int j = 0;
        while((1 << j) < ans[i]) j++;
        cout << j+1 << ' ';
    }
}