#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    int cur = 1;     // 현재 공이 있는 상자 번호 (1~3)
    int ans = 0;     // 상자 3에 공을 넣은 횟수

    for (char c : S) {
        if (c == 'L') {
            // 왼쪽으로 이동하되, 1보다 작아질 수 없음
            cur = max(1, cur - 1);
        } else { // c == 'R'
            // 오른쪽으로 이동하되, 3보다 커질 수 없음
            cur = min(3, cur + 1);
        }
        if (cur == 3) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
