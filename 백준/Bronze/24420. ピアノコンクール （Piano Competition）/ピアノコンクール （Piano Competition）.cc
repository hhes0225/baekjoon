#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long long sum = 0;     // 합
    int mn = 101;          // Ai ≤ 100 이므로 초기값 101
    int mx = -1;           // Ai ≥ 0 이므로 초기값 -1

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        sum += a;
        mn = min(mn, a);
        mx = max(mx, a);
    }

    // 최댓값과 최솟값을 제외
    cout << (sum - mn - mx) << "\n";
    return 0;
}
