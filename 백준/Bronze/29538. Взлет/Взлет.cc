#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M; int N; long long alpha;
    if (!(cin >> M >> N >> alpha)) return 0;
    long long S = M;                // M + sum(m_i)
    for (int i = 0; i < N; ++i) {
        long long mi; cin >> mi;
        S += mi;
    }

    if (alpha >= 1000) {
        cout << "Impossible\n";
        return 0;
    }

    // F_min = alpha * S / (1000 - alpha)
    long double ans = (long double)alpha * (long double)S / (1000.0L - (long double)alpha);
    cout.setf(ios::fixed);
    cout << setprecision(10) << (double)ans << "\n";  // 1e-6 오차 조건 충족
    return 0;
}
