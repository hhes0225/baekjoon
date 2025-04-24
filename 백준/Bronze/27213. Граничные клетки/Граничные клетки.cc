#include <iostream>
using namespace std;

int main() {
    long long m, n;
    cin >> m >> n;

    if (m == 1 || n == 1) {
        cout << m * n << '\n';  // 모두 경계
    } else {
        cout << 2 * n + 2 * m - 4 << '\n';  // 위 + 아래 + 좌 + 우 - 모서리 중복 제거
    }

    return 0;
}
