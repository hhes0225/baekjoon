#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    if (!(cin >> n >> p)) return 0;

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        sum += a; // 발사 횟수 누적
    }

    long long move = (n - 1) + min(p - 1, n - p);
    cout << (sum + move) << '\n';
    return 0;
}
