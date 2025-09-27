#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;

    // 차량 번호가 1..1000 이므로 배열로 입차시간 기록 (-1은 미기록)
    const int MAX_ID = 1000;
    vector<long long> inTime(MAX_ID + 1, -1);

    for (int i = 0; i < M; ++i) {
        long long T; int N;
        cin >> T >> N;

        if (inTime[N] == -1) {
            // 첫 등장: 입차
            inTime[N] = T;
        } else {
            // 두 번째 등장: 출차 -> 머문 시간 출력
            long long stay = T - inTime[N];
            cout << N << ' ' << stay << '\n';
            inTime[N] = -1; // (선택) 정리
        }
    }
    return 0;
}
