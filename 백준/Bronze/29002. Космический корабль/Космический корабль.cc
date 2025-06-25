#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int bossIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] * 2 == sum) {   // 2 * f_i == S  →  보스
            bossIdx = i;
            break;               // 보스는 유일하다고 보장
        }
    }

    // 보스가 아닌 적들을 먼저, 보스는 맨 뒤에 출력
    for (int i = 0; i < n; ++i) {
        if (i == bossIdx) continue;   // 건너뛰기
        cout << a[i] << ' ';
    }
    cout << a[bossIdx] << '\n';       // 마지막에 보스 출력
    return 0;
}
