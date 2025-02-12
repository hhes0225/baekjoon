#include <iostream>
using namespace std;

int main() {
    // 입력 받기
    int n, a, b, s, t;
    cin >> n >> a >> b;
    cin >> s >> t;

    // 요금제 판별
    if (s >= a + 1 && s <= b - 1 && t >= a + 1 && t <= b - 1) {
        cout << "City" << endl;
    } 
    else if ((s <= a && t <= a) || (s >= b && t >= b)) {
        cout << "Outside" << endl;
    } 
    else {
        cout << "Full" << endl;
    }

    return 0;
}
