#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r; 
    string avail;
    if (!(cin >> r)) return 0;
    cin >> avail;

    auto baseDiv = [&]() -> int {
        if (r <= 1600) return 3;
        if (r <= 1900) return 2;
        return 1;
    }();

    // 기본 디비전이 열리면 그 디비전만 출력
    if (avail.find(char('0' + baseDiv)) != string::npos) {
        cout << baseDiv << '\n';
        return 0;
    }

    // 아니면 가능한 디비전 전부 출력 (필요 시 별표)
    for (char c : avail) {
        int d = c - '0';
        bool star = false;
        if (d == 3 && r > 1600) star = true;
        else if (d == 2 && r > 1900) star = true;
        // d == 1 은 상한이 없어 절대 별표 아님
        cout << d << (star ? "*" : "") << '\n';
    }
    return 0;
}
