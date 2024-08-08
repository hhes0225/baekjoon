#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
vector<int> arr;
vector<bool> row;
vector<bool> x1;
vector<bool> x2;

// 백트래킹을 사용하여 N-Queen 문제를 해결하는 함수
void Backtracking(int n) {
    // 모든 행에 퀸을 놓은 경우
    if (n == N) {
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        exit(0); // 아예 종료
    }

    // 이미 퀸이 놓여 있는 경우 다음 행으로 이동
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
            x2[arr[i] - 1 + (N - 1 - i)] = false; // 오른쪽 아래 방향 대각선 제거
        }
    }

    Backtracking(0); // 0번째 줄부터 함수 실행
    cout << -1 << endl;

    return 0;
}
