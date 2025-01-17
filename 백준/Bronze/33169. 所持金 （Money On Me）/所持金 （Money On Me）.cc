#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B; // A와 B를 입력받음

    int total = 1000 * A + 10000 * B; // 1000원짜리와 10000원짜리 합 계산

    cout << total << endl; // 결과 출력

    return 0;
}
