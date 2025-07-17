#include <iostream>
using namespace std;

int main() {
    int k; // 현재 키
    int w; // 목표 키
    int m; // 한 번 칠 때마다 자라는 키

    cin >> k >> w >> m;

    if (k >= w) {
        cout << 0 << '\n'; // 이미 키가 크거나 같으면 안 쳐도 됨
    } else {
        cout << (w - k + m - 1) / m << '\n'; // 올림 나눗셈
    }

    return 0;
}
