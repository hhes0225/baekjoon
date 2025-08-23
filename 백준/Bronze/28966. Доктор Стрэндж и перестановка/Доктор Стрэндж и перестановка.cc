#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> misOdd, misEven;   // 불일치 위치들
    vector<int> oddIdx, evenIdx;   // 같은 홀짝 인덱스 후보 (불일치 0개일 때 사용)

    for (int i = 1; i <= n; ++i) {
        if (i % 2) oddIdx.push_back(i);
        else evenIdx.push_back(i);

        int ip = i & 1;
        int vp = a[i] & 1;
        if (ip != vp) {
            if (ip == 1) misOdd.push_back(i);   // 홀수 인덱스에 짝수 값
            else          misEven.push_back(i); // 짝수 인덱스에 홀수 값
        }
    }

    // 경우 1: 불일치가 정확히 2개 (각각 한 개씩) → 서로 교환
    if (misOdd.size() == 1 && misEven.size() == 1) {
        cout << misOdd[0] << ' ' << misEven[0] << "\n";
        return 0;
    }

    // 경우 2: 불일치가 0개 → 같은 홀짝 인덱스끼리 교환 (n=2면 불가)
    if (misOdd.empty() && misEven.empty()) {
        if ((int)oddIdx.size() >= 2) {
            cout << oddIdx[0] << ' ' << oddIdx[1] << "\n";
            return 0;
        }
        if ((int)evenIdx.size() >= 2) {
            cout << evenIdx[0] << ' ' << evenIdx[1] << "\n";
            return 0;
        }
        // n=2 같은 케이스: 같은 홀짝 인덱스 쌍이 없음
        cout << -1 << ' ' << -1 << "\n";
        return 0;
    }

    // 그 외는 불가능
    cout << -1 << ' ' << -1 << "\n";
    return 0;
}
