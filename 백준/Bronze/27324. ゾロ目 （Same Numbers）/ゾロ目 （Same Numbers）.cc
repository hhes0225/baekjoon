#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int tens = N / 10;   // 십의 자리
    int ones = N % 10;   // 일의 자리

    if (tens == ones) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
