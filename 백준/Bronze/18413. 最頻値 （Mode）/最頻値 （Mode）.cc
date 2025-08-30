#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> B(M+1, 0); // 1~M 인덱스 사용
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        B[x]++; // x 값 등장 횟수 증가
    }

    int answer = 0;
    for (int j = 1; j <= M; j++) {
        answer = max(answer, B[j]);
    }

    cout << answer << "\n";
    return 0;
}
