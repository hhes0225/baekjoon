#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> colors(N);
    for (int i = 0; i < N; ++i) {
        cin >> colors[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int length = 2; length <= N; ++length) {
        for (int i = 0; i <= N - length; ++i) {
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
