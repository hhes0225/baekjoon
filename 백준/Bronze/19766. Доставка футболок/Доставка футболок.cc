#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k, t;
    if (!(cin >> n >> k >> t)) return 0;

    vector<long long> z(n);         // z[0]: 사무실 -> 1번, z[i]: i->i+1
    for (int i = 0; i < n; ++i) cin >> z[i];

    vector<long long> s(n+1);       // 1-based로 받기 편하게
    for (int i = 1; i <= n; ++i) cin >> s[i];

    long long cur = 0;               // 현재 시각
    for (int i = 1; i <= n; ++i) {
        long long arr = cur + z[i-1];                 // i번째 수령지 도착 시각
        if (s[i] <= arr + k) {
            // s[i] 시각에 도착해 있거나, k분 내에 도착하면 전달
            cur = max(arr, s[i]) + t;                 // 전달 종료 시각
        } else {
            // k분 기다려도 못 만남 → 부재 처리 후 이동
            cur = arr + k;
        }
    }

    cout << cur << '\n';
    return 0;
}
