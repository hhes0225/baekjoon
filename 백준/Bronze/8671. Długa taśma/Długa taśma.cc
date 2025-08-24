#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long x, mn = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x < mn) mn = x;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << (long double)mn << "\n";
    return 0;
}
