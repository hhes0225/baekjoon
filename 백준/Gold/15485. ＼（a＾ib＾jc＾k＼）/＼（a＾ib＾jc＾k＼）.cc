#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

int main() {
    string S;
    cin >> S;

    ll dp_a = 0;     // a^i
    ll dp_ab = 0;    // a^i b^j
    ll dp_abc = 0;   // a^i b^j c^k

    for (char ch : S) {
        if (ch == 'a') {
            dp_a = (dp_a * 2 + 1) % MOD;
        } else if (ch == 'b') {
            dp_ab = (dp_ab * 2 + dp_a) % MOD;
        } else if (ch == 'c') {
            dp_abc = (dp_abc * 2 + dp_ab) % MOD;
        }
    }

    cout << dp_abc << "\n";
    return 0;
}
