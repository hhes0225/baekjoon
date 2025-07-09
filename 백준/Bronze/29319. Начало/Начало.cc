#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;                   // 그룹 수
    if (!(cin >> n)) return 0;

    long long sum = 0;       // 모든 반지의 합
    int mx = 0;              // 최대 그룹 크기

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << sum - mx << '\n';
    return 0;
}
