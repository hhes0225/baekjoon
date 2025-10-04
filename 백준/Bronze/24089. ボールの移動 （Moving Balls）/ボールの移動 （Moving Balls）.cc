#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) pos[i] = i;  // 공 i는 상자 i에서 시작

    for (int j = 0; j < M; ++j) {
        int X, Y; 
        cin >> X >> Y;
        pos[X] = Y;                           // 공 X를 상자 Y로 이동
    }

    for (int i = 1; i <= N; ++i) {
        cout << pos[i] << '\n';
    }
    return 0;
}
