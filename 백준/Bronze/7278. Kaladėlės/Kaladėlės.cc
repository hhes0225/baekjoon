#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int a, b, c;
    if (!(cin >> N)) return 0;
    cin >> a >> b >> c;

    vector<int> H = {a, b, c};

    long long bestDiff = (1LL<<60);
    int bestH = -1;
    int bestTower = -1;

    for (int h : H) {
        // 후보 배수 k: floor, ceil (단 k>=1)
        int k1 = N / h;              // floor
        if (k1 < 1) k1 = 1;
        int k2 = (N + h - 1) / h;    // ceil (항상 >=1)

        // 두 후보를 각각 평가
        for (int k : {k1, k2}) {
            int tower = h * k;
            long long diff = llabs((long long)tower - N);

            // 우선순위: 차이 |tower-N| 작음 -> tower 작음 -> h 작음
            if (diff < bestDiff ||
               (diff == bestDiff && (tower < bestTower ||
               (tower == bestTower && h < bestH)))) {
                bestDiff = diff;
                bestH = h;
                bestTower = tower;
            }
        }
    }

    cout << bestH << ' ' << bestTower << '\n';
    return 0;
}
