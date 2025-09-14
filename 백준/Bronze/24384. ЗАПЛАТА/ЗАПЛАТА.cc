#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;

    long long totalLen = 0; // 지금까지 이어붙인 총 길이
    for (int i = 1; ; i++) {
        string s = to_string(1LL * i * i * i); // i^3 문자열
        if (totalLen + (int)s.size() >= k) {
            // k번째 숫자가 이 안에 있음
            int pos = k - totalLen - 1; // 문자열 내 인덱스(0-based)
            cout << s[pos] << "\n";
            break;
        }
        totalLen += s.size();
    }
    return 0;
}
