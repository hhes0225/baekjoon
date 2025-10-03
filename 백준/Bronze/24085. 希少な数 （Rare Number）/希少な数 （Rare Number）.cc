#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    const int MAXV = 2000;
    vector<int> cnt(MAXV + 1, 0);

    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }

    int bestVal = -1;
    int bestFreq = INT_MAX;

    for (int v = 1; v <= MAXV; ++v) {
        if (cnt[v] > 0) {
            if (cnt[v] < bestFreq || (cnt[v] == bestFreq && v < bestVal)) {
                bestFreq = cnt[v];
                bestVal = v;
            }
        }
    }

    cout << bestVal << '\n';
    return 0;
}
