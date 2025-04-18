#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int w, l, h;
    cin >> w >> l >> h;

    int mn = min(w, l);
    int mx = max(w, l);

    // 조건 확인
    if (mn >= 2 * h && mx <= 2 * mn) {
        cout << "good" << endl;
    } else {
        cout << "bad" << endl;
    }

    return 0;
}
