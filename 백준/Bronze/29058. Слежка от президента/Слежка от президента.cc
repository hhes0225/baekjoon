#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<string> docs(n, "");   // 각 창의 문서
    string clip = "";             // 클립보드
    int cur = 0;                  // 현재 창 인덱스

    string cmd;
    // 개행 남아 있을 수 있으니 바로 getline 사용 대비
    // 하지만 여기선 cin >> 로 충분 (명령어가 공백 없는 토큰이므로)
    for (int i = 0; i < m; ++i) {
        cin >> cmd;

        if (cmd == "Backspace") {
            if (!docs[cur].empty()) docs[cur].pop_back();
        } else if (cmd == "Copy") {
            // 마지막 k글자 복사
            int len = (int)docs[cur].size();
            int take = min(k, len);
            clip = docs[cur].substr(len - take, take);
        } else if (cmd == "Paste") {
            if (!clip.empty()) docs[cur] += clip;
        } else if (cmd == "Next") {
            cur = (cur + 1) % n;
        } else {
            // 소문자 한 글자
            // 문제 정의상 라틴 소문자만 문자 입력으로 옴
            // 안전하게 처리
            if (cmd.size() == 1 && cmd[0] >= 'a' && cmd[0] <= 'z') {
                docs[cur].push_back(cmd[0]);
            } else {
                // 혹시 모를 예외 입력은 무시
            }
        }
    }

    // 출력: 현재 창의 화면(마지막 k글자). 비면 Empty
    if (docs[cur].empty()) {
        cout << "Empty\n";
    } else {
        int len = (int)docs[cur].size();
        if (len <= k) cout << docs[cur] << "\n";
        else cout << docs[cur].substr(len - k, k) << "\n";
    }

    return 0;
}
