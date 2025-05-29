#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, s, b;
    cin >> t >> a >> s >> b;

    vector<int> numbers(t + 1, 0);
    vector<vector<int>> dp(t + 1, vector<int>(a + 1, 0));

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        numbers[temp]++;
    }

    // dp[i][j]: i번째 숫자까지 사용해서 j개를 선택하는 경우의 수
    dp[0][0] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= a; j++) {
            dp[i][j] = dp[i - 1][j]; // 이전 숫자 조합 복사
            for (int k = 1; k <= numbers[i] && k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }

    int total = 0;
    for (int i = s; i <= b; i++) {
        total = (total + dp[t][i]) % MOD;
    }

    cout << total << '\n';
    return 0;
}

