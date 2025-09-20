#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        if (!(cin >> n >> m)) return 0;
        if (n == 0 && m == 0) break;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int j = 0; j < m; ++j) cin >> b[j];

        long long cnt[10] = {0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = a[i] * b[j];       // 최대 1,000,000
                while (x > 0) {            // 각 자리수 카운트
                    cnt[x % 10]++;
                    x /= 10;
                }
            }
        }

        for (int d = 0; d < 10; ++d) {
            if (d) cout << ' ';
            cout << cnt[d];
        }
        cout << '\n';
    }
    return 0;
}
