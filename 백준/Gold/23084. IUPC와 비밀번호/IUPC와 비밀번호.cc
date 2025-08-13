#include <bits/stdc++.h>
using namespace std;

int diff26(const array<int,26>& a, const array<int,26>& b){
    int d = 0;
    for(int i=0;i<26;i++) d += abs(a[i]-b[i]);
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; int N;
    cin >> S;
    cin >> N;

    const int L = (int)S.size();

    // S의 빈도 미리 계산
    array<int,26> cntS{}; cntS.fill(0);
    for(char c: S) cntS[c-'a']++;

    while(N--){
        string T; cin >> T;
        int M = (int)T.size();

        // 1) |T| < |S| -> NO
        if(M < L){ cout << "NO\n"; continue; }

        // 2) |T| == |S|
        if(M == L){
            array<int,26> cntW{}; cntW.fill(0);
            for(char c: T) cntW[c-'a']++;
            int d = diff26(cntW, cntS);
            // 딱 한 글자 차이(diff==2)만 YES, 나머지(0 포함) NO
            cout << (d==2 ? "YES\n" : "NO\n");
            continue;
        }

        // 3) |T| > |S| : 슬라이딩 윈도우
        array<int,26> cntW{}; cntW.fill(0);
        // 첫 윈도우 [0..L-1]
        for(int i=0;i<L;i++) cntW[T[i]-'a']++;

        bool ok = false;
        auto check = [&](){
            int d = diff26(cntW, cntS);
            // diff==0 : 아나그램 존재(수정은 윈도우 밖)
            // diff==2 : 윈도우 안에서 한 글자만 바꾸면 아나그램
            if(d==0 || d==2) return true;
            return false;
        };

        if(check()) ok = true;

        // 슬라이딩
        for(int r=L; !ok && r<M; r++){
            int l = r - L;               // 빠질 문자 위치
            cntW[T[l]-'a']--;            // 왼쪽 문자 제거
            cntW[T[r]-'a']++;            // 오른쪽 새 문자 추가
            if(check()) ok = true;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
