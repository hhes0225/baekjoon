#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll R0, W0, C, R;
    while (cin >> R0 >> W0 >> C >> R) {
        if (R0 == 0 && W0 == 0 && C == 0 && R == 0) break;

        ll target = C * W0;          // C W0
        if (R0 >= target) {
            cout << 0 << '\n';       // 물만 추가(또는 아무것도 X)
        } else {
            ll need = target - R0;   // 부족한 g
            ll X = (need + R - 1) / R; // 올림 나눗셈
            cout << X << '\n';
        }
    }
    return 0;
}
