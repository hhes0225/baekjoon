#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    // 만날 수 있는 구간의 시작과 끝
    int start = max(l1, l2);
    int end   = min(r1, r2);

    // 겹치는 구간이 없으면 0
    if (start > end) {
        cout << 0 << "\n";
        return 0;
    }

    // 겹치는 분 수
    int ans = end - start + 1;

    // k분이 그 구간에 있으면 한 분 빼기
    if (k >= start && k <= end) {
        ans--;
    }

    // 혹시 음수가 될 수 있으니 0 미만이면 0으로
    cout << max(ans, 0) << "\n";
    return 0;
}
