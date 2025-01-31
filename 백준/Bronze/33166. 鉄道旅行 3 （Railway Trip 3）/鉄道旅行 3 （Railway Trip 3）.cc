#include <iostream>
using namespace std;

int main() {
    int P, Q, A, B;
    cin >> P >> Q;  // P: 기본 요금 적용 거리, Q: 총 이동 거리
    cin >> A >> B;  // A: 기본 요금, B: 이후 요금

    int totalFare = 0;

    if (Q <= P) {
        //전체 이동 거리가 기본 거리 P보다 작거나 같다면, A 요금만 적용
        totalFare = Q * A;
    } else {
        //처음 P km까지는 A 요금 적용, 이후 Q-P km는 B 요금 적용
        totalFare = (P * A) + ((Q - P) * B);
    }

    cout << totalFare << endl;  // 총 요금 출력

    return 0;
}
