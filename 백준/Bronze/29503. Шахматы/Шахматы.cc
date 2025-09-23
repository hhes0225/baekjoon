#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 초기 보드 입력
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i]; // 각 줄 8글자
    }

    int n; 
    cin >> n;

    string ans;
    ans.reserve(n);

    auto toIndex = [](char file, char rank) {
        int c = file - 'a';          // 0..7
        int r = 8 - (rank - '0');    // '8'->0, '1'->7
        return pair<int,int>{r, c};
    };

    for (int i = 0; i < n; ++i) {
        string mv; 
        cin >> mv;                   // 예: "b5b3"
        char fFile = mv[0], fRank = mv[1];
        char tFile = mv[2], tRank = mv[3];

        auto [r1, c1] = toIndex(fFile, fRank);
        auto [r2, c2] = toIndex(tFile, tRank);

        char piece = board[r1][c1];  // 이 턴에 이동한 기물
        ans.push_back(piece);

        board[r2][c2] = piece;       // 이동/잡기 반영
        board[r1][c1] = '.';         // 원위치 비우기
    }

    cout << ans << '\n';
    return 0;
}
