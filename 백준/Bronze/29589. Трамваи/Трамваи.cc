#include <bits/stdc++.h>
using namespace std;

int toMin(const string& s) {
    // "hh:mm" -> minutes
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> tram(n);
    for (int i = 0; i < n; ++i) {
        string t; cin >> t;
        tram[i] = toMin(t);
    }

    vector<int> passT(m);
    for (int i = 0; i < m; ++i) {
        string t; cin >> t;
        passT[i] = toMin(t);
    }

    vector<int> ans(m, -1);
    queue<int> q;          // 대기열: 승객 인덱스
    int pi = 0;            // 아직 큐에 넣지 않은 다음 승객의 인덱스

    for (int ti = 0; ti < n; ++ti) {
        int T = tram[ti];

        // 트램 시각 T까지 도착한 승객을 대기열에 넣기 (도착 시각 == T도 탑승 가능)
        while (pi < m && passT[pi] <= T) {
            q.push(pi);
            ++pi;
        }

        // 현재 트램에 최대 k명 탑승
        for (int cap = 0; cap < k && !q.empty(); ++cap) {
            int idx = q.front(); q.pop();
            ans[idx] = ti + 1; // 트램 번호는 1부터
        }
    }

    // 남은 승객(ans가 여전히 -1)은 출력 시 그대로 -1
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}