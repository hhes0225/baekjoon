#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        int base = (i - 1) * n;
        if (i % 2 == 1) {
            // 홀수 행: 왼쪽 -> 오른쪽
            for (int j = 1; j <= n; j++) {
                if (j > 1) cout << ' ';
                cout << base + j;
            }
        } else {
            // 짝수 행: 오른쪽 -> 왼쪽
            for (int j = n; j >= 1; j--) {
                if (j != n) cout << ' ';
                cout << base + j;
            }
        }
        cout << '\n';
    }
    return 0;
}
