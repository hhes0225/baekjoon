#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    vector<int> freq(n + 2, 0); // 숫자 범위: 1..n+1
    for (int i = 0; i < n; ++i) {
        int a, b; 
        cin >> a >> b;
        ++freq[a];
        ++freq[b];
    }

    int mx = 0;
    for (int v = 1; v <= n + 1; ++v) mx = max(mx, freq[v]);

    cout << (n - mx) << '\n';
    return 0;
}
