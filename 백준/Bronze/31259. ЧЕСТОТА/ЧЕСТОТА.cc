#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cnt(26, 0);
    char ch;

    // 1) 입력: '@'까지 읽어 빈도 계산 (대소문자 구분 X)
    while (cin.get(ch)) {
        if (ch == '@') break;
        if ('a' <= ch && ch <= 'z') ch = char(ch - 'a' + 'A');
        if ('A' <= ch && ch <= 'Z') cnt[ch - 'A']++;
    }

    // 2) 최댓값 높이
    int mx = 0;
    for (int v : cnt) mx = max(mx, v);

    // 3) 위에서부터 세로 히스토그램 출력
    for (int h = mx; h >= 1; --h) {
        for (int i = 0; i < 26; ++i) {
            cout << (cnt[i] >= h ? char('A' + i) : ' ');
        }
        cout << '\n';
    }

    // 4) 구분선과 알파벳 라벨
    for (int i = 0; i < 26; ++i) cout << '-';
    cout << '\n';
    for (int i = 0; i < 26; ++i) cout << char('A' + i);
    cout << '\n';

    return 0;
}
