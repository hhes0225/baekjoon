#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tb;  // 원본 테이블
vector<vector<int>> dp;  // 누적합 테이블

void memoi(int n) {
    // dp 배열 초기화 및 부분합 계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = tb[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

int solution(int fromy, int fromx, int toy, int tox) {
    // 부분합 계산
    return dp[toy][tox] - dp[fromy - 1][tox] - dp[toy][fromx - 1] + dp[fromy - 1][fromx - 1];
}

int main() {
    ios::sync_with_stdio(false);  // C 표준 입출력 비활성화
    cin.tie(NULL);  // 입력 묶음 비활성화

    int n, m;
    cin >> n >> m;

    tb.resize(n + 1, vector<int>(n + 1, 0));
    dp.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tb[i][j];
        }
    }

    memoi(n);  // 누적합 테이블 계산

    for (int i = 0; i < m; i++) {
        int fromy, fromx, toy, tox;
        cin >> fromy >> fromx >> toy >> tox;

        int result = solution(fromy, fromx, toy, tox);
        cout << result << '\n';  // 개행 문자 사용하여 빠르게 출력
    }

    return 0;
}
