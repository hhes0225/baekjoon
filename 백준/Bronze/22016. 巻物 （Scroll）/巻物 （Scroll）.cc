#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string T;
    cin >> N >> K >> T;

    string S = T;                   // 기본은 그대로 복사
    for (int i = K - 1; i < N; ++i) {  // K번째(1-indexed)부터 끝까지 뒤집기
        unsigned char c = static_cast<unsigned char>(S[i]);
        if (islower(c)) S[i] = toupper(c);
        else            S[i] = tolower(c);
    }

    cout << S << '\n';
    return 0;
}
