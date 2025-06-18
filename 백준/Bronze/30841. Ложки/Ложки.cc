#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B;
    cin >> A >> B;
    if (A + B == 0) {
        cout << 0 << "\n";
    } else {
        ll ans = (A * B) / (A + B);
        cout << ans << "\n";
    }
    return 0;
}
