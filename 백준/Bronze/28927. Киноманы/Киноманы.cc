#include <iostream>
using namespace std;

int main() {
    // 입력 변수 선언
    int t1, e1, f1; // Max's data
    int t2, e2, f2; // Mel's data

    // 입력 받기
    cin >> t1 >> e1 >> f1;
    cin >> t2 >> e2 >> f2;

    // 시간 계산
    int time_max = t1 * 3 + e1 * 20 + f1 * 120; // Max의 총 시간
    int time_mel = t2 * 3 + e2 * 20 + f2 * 120; // Mel의 총 시간

    // 결과 비교 및 출력
    if (time_max > time_mel) {
        cout << "Max" << endl;
    } else if (time_mel > time_max) {
        cout << "Mel" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
