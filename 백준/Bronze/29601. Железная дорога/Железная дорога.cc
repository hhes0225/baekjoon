#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    if(!(cin >> s)) return 0;
    
    char type = s[0];                 // 'R' or 'C'
    int n = stoi(s.substr(1));        // seat number
    
    // 유효성 검사
    if (type == 'C' && (n < 1 || n > 36)) {
        cout << -1 << "\n";
        return 0;
    }
    if (type == 'R' && (n < 1 || n > 54)) {
        cout << -1 << "\n";
        return 0;
    }

    int a = -1; // 쿠페 번호
    int b = -1; // 0: 측면, 1: 쿠페
    int c = (n % 2 == 0) ? 1 : -1; // 짝수 위(1), 홀수 아래(-1)

    if (type == 'C') {
        // 쿠페 객차: 전부 쿠페 좌석
        a = (n - 1) / 4 + 1;
        b = 1;
        cout << a << " " << b << " " << c << "\n";
        return 0;
    }

    // type == 'R' (플라츠카르트)
    if (1 <= n && n <= 36) {
        // 쿠페 좌석
        a = (n - 1) / 4 + 1;
        b = 1;
    } else {
        // 측면 좌석(37~54): 번호는 뒤에서부터 매겨짐
        a = (54 - n) / 2 + 1; // 54,53→1 / 52,51→2 / ... / 38,37→9
        b = 0;
    }

    cout << a << " " << b << " " << c << "\n";
    return 0;
}
