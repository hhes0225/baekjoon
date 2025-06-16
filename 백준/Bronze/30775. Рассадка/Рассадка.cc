#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M;
    int K;
    cin >> M >> K;

    ll S = 0;
    for (int i = 0; i < K; i++) {
        ll n;
        cin >> n;
        S += n;
    }

    // compact 분배 시 한 강의실에 들어갈 최대 인원
    // ceil(S/M) = (S + M - 1) / M
    ll answer = (S + M - 1) / M;
    cout << answer << "\n";
    return 0;
}
