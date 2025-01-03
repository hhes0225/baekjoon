#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B; // 두 정수를 입력받음

    if (A < B) {
        cout << -1 << endl; // A < B인 경우 -1 출력
    } else if (A == B) {
        cout << 0 << endl; // A = B인 경우 0 출력
    } else {
        cout << 1 << endl; // A > B인 경우 1 출력
    }

    return 0;
}
