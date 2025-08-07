#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> S(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> S[i];
    }

    long long A;
    int D;
    cin >> A >> D;

    int upper = (N + D - 1) / D;

    // dp[j][k]: 최대 j번 A를 사용하여 시점 k까지 얻을 수 있는 최대 점수
    // 시점 k는 0부터 N+D-1까지
    int width = N + D;
    vector<vector<long long>> dp(upper + 1, vector<long long>(width, 0LL));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= upper; ++j) {
            // j>0인데 이전 시점에 도달하지 못했으면 건너뛰기
            if (j != 0 && dp[j][i-1] == 0) continue;

            // S[i]를 선택하는 경우
            dp[j][i] = max(dp[j][i], dp[j][i-1] + S[i]);

            // A를 사용하여 D일 후 시점으로 점프하는 경우
            if (j < upper) {
                int k = i + D - 1;
                dp[j+1][k] = max(dp[j+1][k], dp[j][i-1] + A);
            }
        }
    }

    // 최소 j를 찾아서 출력
    for (int j = 0; j <= upper; ++j) {
        long long best = *max_element(dp[j].begin(), dp[j].end());
        if (best >= M) {
            cout << j << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}
