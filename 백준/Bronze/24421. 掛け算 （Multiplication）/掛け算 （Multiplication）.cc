#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if (!(cin >> N)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 값 범위가 1..999 이므로 크기 1000짜리 카운터 사용
    const int MAXV = 999;
    vector<int> rightCnt(MAXV + 1, 0);
    for (int v : A) ++rightCnt[v];

    long long ans = 0;

    for (int j = 0; j < N; ++j) {
        // k > j 조건을 위해 현재 A[j]는 오른쪽에서 제거
        --rightCnt[A[j]];

        for (int i = 0; i < j; ++i) {
            long long p = 1LL * A[i] * A[j];
            if (p <= MAXV) ans += rightCnt[(int)p];
        }
    }

    cout << ans << '\n';
    return 0;
}
