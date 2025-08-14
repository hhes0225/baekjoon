#include <bits/stdc++.h>
using namespace std;

// 두 알파벳 빈도 배열의 차이를 구하는 함수
int getDiff(const vector<int>& a, const vector<int>& b) {
    int d = 0;
    for (int i = 0; i < 26; i++) {
        d += abs(a[i] - b[i]);
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    int N;
    cin >> S >> N;
    int L = (int)S.size();

    // S의 빈도 계산
    vector<int> cntS(26, 0);
    for (int i = 0; i < L; i++) {
        cntS[S[i] - 'a']++;
    }

    for (int t = 0; t < N; t++) {
        string T;
        cin >> T;
        int M = (int)T.size();

        // 1) 길이 비교
        if (M < L) {
            cout << "NO\n";
            continue;
        }

        // 2) 길이가 같은 경우
        if (M == L) {
            vector<int> cnt(26, 0);
            for (int i = 0; i < M; i++) {
                cnt[T[i] - 'a']++;
            }
            int diff = getDiff(cnt, cntS);
            if (diff == 2) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        // 3) 길이가 더 긴 경우: 슬라이딩 윈도우
        vector<int> cnt(26, 0);
        // 첫 윈도우 초기화
        for (int i = 0; i < L; i++) {
            cnt[T[i] - 'a']++;
        }

        bool ok = false;
        if (getDiff(cnt, cntS) == 0 || getDiff(cnt, cntS) == 2) {
            ok = true;
        }

        // 윈도우 이동
        for (int r = L; r < M && !ok; r++) {
            cnt[T[r - L] - 'a']--; // 왼쪽 문자 제거
            cnt[T[r] - 'a']++;     // 오른쪽 문자 추가
            int diff = getDiff(cnt, cntS);
            if (diff == 0 || diff == 2) {
                ok = true;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
