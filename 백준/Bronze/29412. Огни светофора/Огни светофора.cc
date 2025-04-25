#include <iostream>
using namespace std;

int main() {
    int g, gb, y, r, ry, T;
    cin >> g >> gb >> y >> r >> ry;
    cin >> T;

    int cycle = g + gb + y + r + ry;

    long long red = 0, yellow = 0, green = 0;

    int full_cycles = T / cycle;
    int remain_time = T % cycle;

    // 전체 사이클 반복으로 얻는 시간
    red += full_cycles * (r + ry);
    yellow += full_cycles * (y + ry);
    green += full_cycles * (g + gb / 2);

    // 남은 시간 처리
    int time = 0;

    // 초록 (g초)
    if (remain_time > 0) {
        int t = min(remain_time, g);
        green += t;
        remain_time -= t;
    }

    // 깜빡이는 초록 (gb초 동안 절반)
    if (remain_time > 0) {
        int t = min(remain_time, gb);
        green += t / 2;
        remain_time -= t;
    }

    // 노랑 (y초)
    if (remain_time > 0) {
        int t = min(remain_time, y);
        yellow += t;
        remain_time -= t;
    }

    // 빨강 (r초)
    if (remain_time > 0) {
        int t = min(remain_time, r);
        red += t;
        remain_time -= t;
    }

    // 빨강+노랑 (ry초)
    if (remain_time > 0) {
        int t = min(remain_time, ry);
        red += t;
        yellow += t;
        remain_time -= t;
    }

    cout << red << " " << yellow << " " << green << endl;

    return 0;
}
