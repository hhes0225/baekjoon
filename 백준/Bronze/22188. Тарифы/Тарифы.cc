#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    if (!(cin >> n >> m)) return 0;

    struct Plan { long long c; int t; long long p; };
    vector<Plan> plans(n);
    for (int i = 0; i < n; ++i) {
        long long c, p; int t;
        cin >> c >> t >> p;              // c: rubles, t: seconds, p: kopecks
        plans[i] = {c * 100, t, p};      // 모두 kopecks로 맞춤 (c*100)
    }

    vector<int> d(m);
    for (int i = 0; i < m; ++i) cin >> d[i];

    long long bestCost = LLONG_MAX;
    int bestIdx = 1;

    for (int i = 0; i < n; ++i) {
        long long total = plans[i].c;    // 기본료(코페이카)
        int t = plans[i].t;
        long long p = plans[i].p;

        for (int T : d) {
            if (T >= t) {
                long long k = (T + t - 1) / t; // ceil(T/t)
                total += k * p;
            }
        }

        if (total < bestCost) {
            bestCost = total;
            bestIdx = i + 1;             // 1-based
        }
    }

    cout << bestIdx << '\n';
    return 0;
}
