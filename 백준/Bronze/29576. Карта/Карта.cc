#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    if (k == 1) {
        if (n == 1) cout << 0 << "\n";
        else cout << -1 << "\n";
        return 0;
    }

    long long numerator = n - 1;
    long long denom = k - 1;

    if (numerator % denom == 0) {
        long long t = numerator / denom;
        cout << t << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
