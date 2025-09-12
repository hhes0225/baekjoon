#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double t, r, v;
    if (!(cin >> t >> r >> v)) return 0;

    // 최소 가능한 실제 속도: max(0, v - 2r/t)
    double vmin = v - 2.0 * r / t;
    if (vmin < 0) vmin = 0.0;

    cout.setf(ios::fixed);
    cout << setprecision(10) << vmin << "\n";
    return 0;
}
