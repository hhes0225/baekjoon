#include <bits/stdc++.h>
using namespace std;

struct Plane {
    int pos;                 // 현재 공항
    vector<char> visited;    // 자신이 방문한 공항
    int cntVisited;          // 방문한 공항 수
    long long dist;          // 누적 거리
    int dir;                 // +1: 시계(1번), -1: 반시계(2번)
    int ap;                  // ap1/ap2
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d, ap1, ap2;
    if (!(cin >> N >> d >> ap1 >> ap2)) return 0;

    // 비행기 초기화: 시작 공항 0
    Plane p1{0, vector<char>(N, 0), 1, 0, +1, ap1};
    Plane p2{0, vector<char>(N, 0), 1, 0, -1, ap2};
    p1.visited[0] = 1;
    p2.visited[0] = 1;

    long long meet = 1;   // 초기 같은 공항
    long long pass = 0;   // 스침(통과 중 상대가 서있는 공항을 지나감)

    auto stepNext = [&](int pos, int dir) {
        pos += dir;
        if (pos < 0) pos += N;
        if (pos >= N) pos -= N;
        return pos;
    };

    auto fly_once = [&](Plane &me, Plane &other) {
        if (me.cntVisited == N) return; // 이미 모든 공항 방문 완료면 아무 것도 안 함

        // 1) ap개 공항 '무조건' 통과(착륙 금지)
        for (int s = 0; s < me.ap; ++s) {
            me.pos = stepNext(me.pos, me.dir);
            me.dist += d;
            if (me.pos == other.pos) pass++; // 통과 시 상대가 서 있으면 스침
        }

        // 2) 아직 내가 방문하지 않은 첫 공항 찾아 도착(착륙)
        while (true) {
            me.pos = stepNext(me.pos, me.dir);
            me.dist += d;

            if (!me.visited[me.pos]) {
                // 여기에 착륙
                me.visited[me.pos] = 1;
                me.cntVisited++;
                if (me.pos == other.pos) meet++; // 착륙과 동시에 같은 공항 -> 만남
                break;
            } else {
                // 방문했던 공항이면 통과만
                if (me.pos == other.pos) pass++;
            }
        }
    };

    // 시뮬: 두 기체 모두 N개 방문할 때까지
    while (p1.cntVisited < N || p2.cntVisited < N) {
        if (p1.cntVisited < N) fly_once(p1, p2);
        if (p2.cntVisited < N) fly_once(p2, p1);
    }

    cout << p1.dist << ' ' << p2.dist << ' ' << meet << ' ' << pass << '\n';
    return 0;
}
