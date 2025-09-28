#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(4);
    for (int i = 0; i < 4; ++i) cin >> a[i];

    // 등장 체크 (1..4)
    bool seen[5] = {false, false, false, false, false};
    int zeroCnt = 0, zeroIdx = -1;
    for (int i = 0; i < 4; ++i) {
        if (a[i] == 0) { ++zeroCnt; zeroIdx = i; }
        else seen[a[i]] = true;
    }

    if (zeroCnt == 0) {
        // 빈 칸 없음: 1번, 2번 칸 값 출력
        cout << a[0] << ' ' << a[1] << '\n';
    } else if (zeroCnt == 1) {
        // 빈 칸 하나: (칸 번호, 빠진 숫자)
        int missing = -1;
        for (int v = 1; v <= 4; ++v) if (!seen[v]) { missing = v; break; }
        cout << (zeroIdx + 1) << ' ' << missing << '\n';
    } else { // zeroCnt == 2
        // 빈 칸 둘: 빠진 두 수를 오름차순
        int x = -1, y = -1;
        for (int v = 1; v <= 4; ++v) {
            if (!seen[v]) {
                if (x == -1) x = v;
                else y = v;
            }
        }
        if (x > y) swap(x, y);
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
