#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
    문제 분할(큰 문제-> 작은 문제)
    - 전구 색을 바꾸는 경우, 연속된 같은 색의 전구는 전부 같은 색으로 바뀜
    - 이때, 이를 이용하여 모든 전구의 색이 같아지려면 최소 몇 번 색을 바꾸어야 하는가?

    1. 구간 설정: 전구의 구간 [i, j] 설정.
    (i==시작 전구 인덱스, j==끝 전구 인덱스)

    2. 부분 문제 정의
    : 각 구간 [i, j]에 대해 해당 구간의 전구들을 하나의 색으로 바꾸는 최소 횟수

    3. 재귀적 접근
    : [i, j]를 두 부분으로 나누어 각각의 부분을 하나의 색으로 바꾸는 최소 횟수 구하기
    두 부분을 하나의 색으로 바꾸는 횟수 더하기

    ***
    DP 테이블: 2차원 배열
    - 각 구간 [i, j]에 대해 최소 횟수 저장하기 위함
    1. DP 테이블 정의
    : dp[i][j] == 구간 [i, j]의 전구들을 하나의 색으로 바꾸는 최소 횟수

    2. 초기화
    : dp[i][j]=0

    3. 점화식
    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][i]+c(i,j))
    c(i, j) = 1(colors[i]!=colors[j]) / 0(colors[i]==colors[j])
    (시작 색과 끝 색이 다를 경우 1회 추가, 같을 경우 0)
*/

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int length = 2; length <= N; length++) {
        for (int i = 0; i <= N - length; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (colors[i] != colors[j] ? 1 : 0));
            }
        }
    }

    cout << dp[0][N-1] << endl;

    return 0;
}
