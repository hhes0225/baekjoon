#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> A(N), B(M);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    sort(B.begin(), B.end());

    long long ans = 0;
    for (int x : A) {
        auto it = lower_bound(B.begin(), B.end(), x); // B에서 x 이상 첫 위치
        ans += (B.end() - it);                         // x ≤ Bj 개수
    }

    cout << ans << '\n';
    return 0;
}
