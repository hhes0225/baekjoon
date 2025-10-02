#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int j = 0; j < M; ++j) cin >> B[j];

    // 값 범위가 1..2000 이므로 배열로 존재 표시
    const int MAXV = 2000;
    vector<char> has(MAXV + 1, 0);
    for (int b : B) has[b] = 1;

    int ans = 0;
    for (int a : A) if (has[a]) ++ans;

    cout << ans << '\n';
    return 0;
}
