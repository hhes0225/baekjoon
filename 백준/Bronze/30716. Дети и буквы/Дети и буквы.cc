#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;

    // 1-based 인덱스를 위해 i는 0..n-2 체크, 출력은 i+1, i+2
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) {
            cout << "Yes\n";
            cout << (i + 1) << ' ' << (i + 2) << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
