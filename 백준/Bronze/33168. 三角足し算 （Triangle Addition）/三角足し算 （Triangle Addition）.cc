#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if (!(cin >> N)) return 0;
    vector<long long> cur(N);
    for (int i = 0; i < N; ++i) cin >> cur[i];

    for (int step = 1; step <= N - 1; ++step) {
        int k = (int)cur.size();
        vector<long long> nxt(k - 1);
        for (int i = 0; i < k - 1; ++i) nxt[i] = cur[i] + cur[i + 1];

        for (int i = 0; i < (int)nxt.size(); ++i) {
            if (i) cout << ' ';
            cout << nxt[i];
        }
        cout << '\n';
        cur.swap(nxt);
    }
    return 0;
}
