#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    bool strictly_increasing = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i+1]) { // 증가 깨지는 지점이 있으면 전체를 답으로 사용 가능
            strictly_increasing = false;
            break;
        }
    }

    if (strictly_increasing) {
        cout << 0 << "\n";
    } else {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << i;
        }
        cout << "\n";
    }
    return 0;
}
