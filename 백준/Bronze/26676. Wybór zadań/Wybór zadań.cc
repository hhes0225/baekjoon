#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> count;  // 각 포지션(예: 1A, 5C)의 개수 저장

    for (int i = 0; i < n; ++i) {
        string pos;
        cin >> pos;
        count[pos]++;
    }

    // 각 포지션이 필요한 문제 수 설정
    map<string, int> required;

    // 1~4 라운드의 A/B/C → 각 1개씩 필요
    for (int i = 1; i <= 4; ++i) {
        for (char c = 'A'; c <= 'C'; ++c) {
            string pos = to_string(i) + c;
            required[pos] = 1;
        }
    }

    // 5라운드 A/B/C → 각 2개 필요
    for (char c = 'A'; c <= 'C'; ++c) {
        string pos = "5";
        pos += c;
        required[pos] = 2;
    }

    int total = 0;

    // 각 포지션별로 필요한 개수 이상 있는지 확인
    for (auto [pos, req] : required) {
        if (count[pos] < req) {
            cout << "NIE\n";  // 부족한 포지션이 하나라도 있으면 실패
            return 0;
        }
        total += req;
    }

    // 통과: 모든 포지션에 충분한 아이디어가 있음
    cout << "TAK\n";
    return 0;
}
