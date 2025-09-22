#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    vector<int> d = {a, b, c};
    sort(d.begin(), d.end());          // 가장 작은 숫자 조합부터

    int rank = 0;
    do {
        ++rank;
        int y = d[0]*100 + d[1]*10 + d[2];
        if (y == x) {
            cout << rank << "\n";
            return 0;
        }
    } while (next_permutation(d.begin(), d.end()));

    return 0; // (문제 보장상 여기 도달하지 않음)
}
