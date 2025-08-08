#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<int> diff(m + 2, 0); // 1..m 사용, r+1 접근 위해 +2

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        if (r + 1 <= m) diff[r + 1] -= 1;
    }

    int cur = 0;
    for (int x = 1; x <= m; ++x) {
        cur += diff[x];
        if (cur == 0) {            // 한 번도 안 덮인 보드 존재
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
