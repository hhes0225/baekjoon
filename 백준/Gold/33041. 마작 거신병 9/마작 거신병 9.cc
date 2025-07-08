#include <bits/stdc++.h>
using namespace std;

vector<int> cols;                     // W_i
vector<pair<int,int>> mahjong;        // {9 개수, 1 개수}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H; cin >> H;
    cols.resize(H);
    mahjong.assign(H, {0, 0});

    for (int &x : cols) cin >> x;

    long long ones, nines;            // C, D
    cin >> ones >> nines;
    const long long INF = (1LL<<60);

    /* ---------- 1️⃣ 위 → 아래 : 최소로 9 배치 ---------- */
    long long prevSum = -INF;         // 직전 행 합
    for (int i = 0; i < H; ++i) {
        long long need = 0;
        long long target = prevSum + 1;               // 반드시 초과해야 하는 값
        if (target > cols[i])                         // 1만만으로 부족하면
            need = (target - cols[i] + 7) / 8;        // ceil((target-cols)/8)

        if (need > cols[i] || need > nines) {         // 자리/재고 부족
            cout << -1 << '\n';
            return 0;
        }
        mahjong[i].first = (int)need;                 // 9 개수
        nines           -= need;
        prevSum          = cols[i] + 8 * need;        // Wi + 8·(9개수)
    }

    /* ---------- 2️⃣ 아래 → 위 : 남은 9 배치 (조건 유지) ---------- */
    for (int i = H - 1; i >= 0 && nines > 0; --i) {
        long long curSum    = cols[i] + 8LL * mahjong[i].first;
        long long lowerSum  = (i == H - 1) ? INF :
                              cols[i + 1] + 8LL * mahjong[i + 1].first;

        long long cap       = cols[i] - mahjong[i].first;          // 빈 칸
        long long maxExtra  = (lowerSum - 1 - curSum) / 8;         // 넣을 수 있는 최대 9
        if (maxExtra < 0) maxExtra = 0;

        long long add = min({cap, maxExtra, nines});
        mahjong[i].first += (int)add;
        nines           -= add;
    }

    if (nines != 0) {                         // 9가 남아 있으면 불가
        cout << -1 << '\n';
        return 0;
    }

    /* ---------- 3️⃣ 1 채우기 및 남은 1 검증 ---------- */
    long long onesNeeded = 0;
    for (int i = 0; i < H; ++i) {
        mahjong[i].second = cols[i] - mahjong[i].first;   // 남은 칸은 1
        onesNeeded       += mahjong[i].second;
    }
    if (onesNeeded != ones) {                 // 1 개수 안 맞음
        cout << -1 << '\n';
        return 0;
    }

    /* ---------- 4️⃣ 최종 합 검증 ---------- */
    for (int i = 1; i < H; ++i) {
        long long up   = mahjong[i - 1].first * 9LL + mahjong[i - 1].second;
        long long down = mahjong[i].first     * 9LL + mahjong[i].second;
        if (up >= down) {                     // S_i < S_{i+1} 위배
            cout << -1 << '\n';
            return 0;
        }
    }

    /* ---------- 5️⃣ 출력 ---------- */
    for (auto [nine, one] : mahjong) {
        for (int i = 0; i < nine; ++i) cout << "9 ";
        for (int i = 0; i < one ; ++i) cout << "1 ";
        cout << '\n';
    }
    return 0;
}
