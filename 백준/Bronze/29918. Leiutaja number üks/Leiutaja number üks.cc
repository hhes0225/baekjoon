#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    long long myTotal = 0;          // 아달베르트의 10주 뒤 발명품 수
    long long bestCompetitor = 0;   // 경쟁자 최고 발명품 수

    for (int i = 0; i < 6; ++i) {
        cin >> N >> M;
        long long total = N + 10 * M;  // 10주 뒤 수

        if (i == 0) {           // 첫 줄: 아달베르트
            myTotal = total;
        } else {                // 나머지 5명: 경쟁자
            bestCompetitor = max(bestCompetitor, total);
        }
    }

    long long K = 0;
    if (myTotal <= bestCompetitor) {
        K = bestCompetitor - myTotal + 1;  // 1개 차이로 앞서기
    }

    cout << K << '\n';
    return 0;
}
