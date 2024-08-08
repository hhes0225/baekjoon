#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*
N-Queen 문제는 크기가 n*n인 체스판 위에 N개의 퀸을 
서로 공격할 수 없게 놓는 문제

n-queen 이론 참고
https://kang-james.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9backtracking-%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0-N-Queen-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4

n-queen 구현 참고
https://hoonably.github.io/posts/%EB%B0%B1%EC%A4%80-Python-N-Queen-Easy-30242%EB%B2%88/

퀸은 수직, 수평, 대각선 방향으로 이동 가능하기 때문에,
퀸 위치 기준으로 수직, 수평 대각선 방향에 또 다른 퀸을 놓으면 안됨(공격당함)

수평 방향: 이미 각 행에 퀸을 놓기 때문에 체크할 필요가 없음.(행이 주어짐)
수직 방향: 같은 수직선에 퀸이 놓이지 않도록 체크 필요
대각선 방향: 두 종류의 대각선 체크하여 퀸이 서로 공격하지 못하도록 해야 함.

*/


int N;
vector<int> arr; // 열 번호 저장
vector<bool> row; // 각 열에 퀸이 놓여 있는지 여부 저장
vector<bool> x1; // 우상향 대각선
vector<bool> x2; // 우하향 대각선

// 백트래킹을 사용하여 N-Queen 문제를 해결하는 함수
void Backtracking(int n) {
    // 모든 행에 퀸을 놓은 경우
    if (n == N) {
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        exit(0); // 아예 종료
        //return을 사용하면 현재 함수만 pop되고 호출한 함수로 돌아가서 다른 경로 계속 탐색하게 됨.
        //이로 인해 불필요한 탐색 발생할 수 있음
        //이를 방지하고 바로 종료시키기 위해 exit(0)을 사용함
    }

    // 이미 퀸이 놓여 있는 경우, 퀸을 둘 수 없음. 따라서 다음 행으로 이동
    if (arr[n] != 0) {
        Backtracking(n + 1);
        return;
    }

    // 현재 행에 퀸을 놓을 수 있는 모든 열을 시도
    for (int i = 0; i < N; ++i) {
        // 퀸을 놓을 수 있는지 확인
        if (row[i] && x1[i + n] && x2[i + (N - 1 - n)]) {
            // 퀸을 현재 열에 놓음
            arr[n] = i + 1;
            row[i] = false; // 가로줄 제거
            x1[i + n] = false; // 오른쪽 위 방향 대각선 제거
            x2[i + (N - 1 - n)] = false; // 오른쪽 아래 방향 대각선 제거
            //제거 == 이제 이 곳에는 퀸을 두면 공격받는다

            // 다음 행에 대해 재귀 호출
            Backtracking(n + 1);

            // 백트래킹: 퀸을 되돌림
            row[i] = true;
            x1[i + n] = true;
            x2[i + (N - 1 - n)] = true;
            arr[n] = 0;
        }
    }
}

int main() {
    cin >> N;
    arr.resize(N);
    row.resize(N, true); // 가로줄 초기화
    x1.resize(2 * N, true); // 우상향 대각선 초기화
    x2.resize(2 * N, true); // 우하향 대각선 초기화

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // 이미 놓아진 퀸의 위치를 반영하여 가로줄 및 대각선 제거
    for (int i = 0; i < N; ++i) {
        if (arr[i] != 0) {
            row[arr[i] - 1] = false; // 가로줄 제거
            x1[arr[i] - 1 + i] = false; // 오른쪽 위 방향 대각선 제거
            //arr[i] - 1은 현재 행 i에 놓여 있는 퀸의 열 번호
            //i는 현재 행의 번호
            //arr[i] - 1 + i는 오른쪽 위 방향 대각선의 인덱스
            x2[arr[i] - 1 + (N - 1 - i)] = false; // 오른쪽 아래 방향 대각선 제거
            //(N - 1 - i)는 현재 행 i에서 오른쪽 아래 방향 대각선의 인덱스
            //arr[i] - 1 + (N - 1 - i)는 오른쪽 아래 방향 대각선의 인덱스
        }
    }

    Backtracking(0); // 0번째 줄부터 함수 실행
    cout << -1 << endl;

    return 0;
}
