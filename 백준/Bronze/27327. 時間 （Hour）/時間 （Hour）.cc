#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X; // 입력: X 日

    int hours = X * 24; // 1 日은 24 時間
    cout << hours << endl; // 출력: X 日의 時間 수

    return 0;
}
