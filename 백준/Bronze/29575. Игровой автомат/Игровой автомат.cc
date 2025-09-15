#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    unordered_map<string, long long> pay;
    pay.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        string comb;
        long long w;
        cin >> comb >> w;     // comb는 정확히 4자리 문자열
        pay[comb] = w;        // 조합별 상금 저장
    }

    int m;
    cin >> m;

    long long winSum = 0;     // 총 상금
    for (int i = 0; i < m; ++i) {
        string got;
        cin >> got;           // 나온 조합
        auto it = pay.find(got);
        if (it != pay.end()) winSum += it->second;
    }

    long long cost = 10LL * m;             // 총 비용
    long long net = winSum - cost;         // 자본 변화
    cout << net << '\n';
    return 0;
}
