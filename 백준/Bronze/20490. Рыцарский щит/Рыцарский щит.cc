#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> t1(3), t2(3);
    for (auto& x : t1) cin >> x;
    for (auto& x : t2) cin >> x;

    long long total = 0;
    for (int i = 0; i < 3; ++i) total += t1[i] + t2[i];

    long long best = 0;                     // 최대 min(x,y)
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            best = max(best, min(t1[i], t2[j]));

    cout << total - 2 * best << '\n';
    return 0;
}
