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

    // DP 테이블 초기화: dp[i][j]는 구간 [i, j]를 하나의 색으로 바꾸는 최소 횟수를 의미
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 길이 2 이상인 구간에 대해 DP 테이블 채우기
    for (int length = 2; length <= N; length++) {  // 구간의 길이를 2부터 N까지 점차적으로 증가시킴
        for (int i = 0; i <= N - length; i++) {    // 구간의 시작점 i
            int j = i + length - 1;                // 구간의 끝점 j (구간의 길이가 length)
            dp[i][j] = INT_MAX;                    // dp[i][j]를 최댓값으로 초기화

            for (int k = i; k < j; ++k) {          // 구간 [i, j]를 두 부분 [i, k]와 [k+1, j]로 나누기
                // dp[i][k]: 구간 [i, k]를 하나의 색으로 바꾸는 최소 횟수
                // dp[k+1][j]: 구간 [k+1, j]를 하나의 색으로 바꾸는 최소 횟수
                // colors[i] != colors[j] -> 두 구간을 하나의 색으로 합치려면 1회 추가
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (colors[i] != colors[j] ? 1 : 0));
            }
        }
    }

    // 결과 출력: dp[0][N-1]는 전체 구간 [0, N-1]을 하나의 색으로 바꾸는 최소 횟수
    cout << dp[0][N-1] << endl;

    return 0;
}
