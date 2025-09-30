#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string S;
    cin >> N >> K >> S;

    int r = count(S.begin(), S.end(), 'R');
    if (r == K) cout << 'W' << '\n';
    else        cout << 'R' << '\n';
    return 0;
}
