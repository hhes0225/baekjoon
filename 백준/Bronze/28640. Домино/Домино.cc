#include <bits/stdc++.h>
using namespace std;

pair<int, int> parseDomino(const string& s) {
    int sep = s.find('|');
    int left = count(s.begin(), s.begin() + sep, '.');
    int right = count(s.begin() + sep + 1, s.end(), '.');
    return {left, right};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    pair<int, int> d1 = parseDomino(a);
    pair<int, int> d2 = parseDomino(b);

    // 가능한 모든 경우를 비교
    if (d1.first == d2.first || d1.first == d2.second ||
        d1.second == d2.first || d1.second == d2.second)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
