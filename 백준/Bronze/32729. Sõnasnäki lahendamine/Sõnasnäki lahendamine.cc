#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string letters;
    cin >> letters;

    // 1) 사용 가능한 문자 빈도
    vector<int> available(26, 0);
    for (char c : letters) available[c - 'a']++;

    int N;
    cin >> N;

    // 2) 각 단어 판별
    while (N--) {
        string word;
        cin >> word;
        vector<int> need(26, 0);
        for (char c : word) need[c - 'a']++;

        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (need[i] > available[i]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << word << '\n';
    }

    return 0;
}
