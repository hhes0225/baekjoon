#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    // 1) 길이 3 가능?
    if (C == A) {
        cout << A << B << C << '\n';
        return 0;
    }

    // 2) 길이 4 가능?
    if (B == C) {
        cout << A << B << B << A << '\n';
        return 0;
    }

    // 3) 최소 길이 5
    cout << A << B << C << B << A << '\n';
    return 0;
}
