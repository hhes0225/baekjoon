#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long long>> A(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> A[i][j];
    }

    bool ok = true;
    int strict_cnt = 0;

    for (int i = 0; i < n; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < n; ++j) {
            if (j != i) row_sum += A[i][j];
        }
        if (A[i][i] < row_sum) ok = false;          // 위배
        else if (A[i][i] > row_sum) ++strict_cnt;   // 엄밀히 큼
    }

    if (ok && strict_cnt >= 1) {
        cout << "YES\n" << strict_cnt << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
