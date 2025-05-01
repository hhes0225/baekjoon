#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, s;
vector<ll> dungeon; // 방마다의 점수 정보
ll maxScore = 0;     // 게임 종료 시 최대 점수 저장용

// 오른쪽 방향으로 탐색 (s -> s+1 -> s+2 ...)
int moveRight(int cursor, ll beforeMax) {
    if (cursor == N) return cursor; // 범위 초과 시 종료

    // 현재 점수 변화량: 이전 max 대비 증가분 + 현재 방 점수
    ll v = maxScore - beforeMax + dungeon[cursor];
    cursor++;

    // 오른쪽으로 계속 이동
    while (cursor <= N - 1) {
        if (v + dungeon[cursor] < 0)
            return cursor - 1; // 게임오버 되기 직전 위치에서 멈춤

        // 누적 점수를 현재 방에 반영
        dungeon[cursor] += v;
        v = dungeon[cursor];

        // 최대 점수 갱신
        maxScore = max(maxScore, v);

        cursor++;
    }

    return cursor;
}

// 왼쪽 방향으로 탐색 (s -> s-1 -> s-2 ...)
int moveLeft(int cursor, ll beforeMax) {
    if (cursor == -1) return cursor; // 범위 초과 시 종료

    ll v = maxScore - beforeMax + dungeon[cursor];
    cursor--;

    // 왼쪽으로 계속 이동
    while (cursor >= 0) {
        if (v + dungeon[cursor] < 0)
            return cursor + 1; // 게임오버 되기 직전 위치에서 멈춤

        dungeon[cursor] += v;
        v = dungeon[cursor];

        maxScore = max(maxScore, v);

        cursor--;
    }

    return cursor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> s;
    dungeon.resize(N);
    for (int i = 0; i < N; i++) cin >> dungeon[i];

    // 초기값 설정
    ll lBeforeMax = 0, rBeforeMax = 0;
    int lCursor = s - 1;
    int rCursor = s - 1;

    // 점수가 더 이상 증가하지 않을 때까지 반복
    while (true) {
        rCursor = moveRight(rCursor, rBeforeMax); // 오른쪽으로 이동하며 탐색
        rBeforeMax = maxScore;

        lCursor = moveLeft(lCursor, lBeforeMax);  // 왼쪽으로 이동하며 탐색
        lBeforeMax = maxScore;

        // 점수가 갱신되지 않으면 종료
        if (maxScore == rBeforeMax)
            break;
    }

    cout << maxScore << '\n'; // 최종 점수 출력
    return 0;
}
