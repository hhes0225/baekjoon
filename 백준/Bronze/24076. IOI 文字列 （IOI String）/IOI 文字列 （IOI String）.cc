#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    if (!(cin >> N)) return 0;
    cin >> S; // S 길이 N, 대문자

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        char expect = ((i + 1) % 2 == 1) ? 'I' : 'O'; // 1-based 기준
        if (S[i] != expect) ++ans;
    }
    cout << ans << '\n';
    return 0;
}
