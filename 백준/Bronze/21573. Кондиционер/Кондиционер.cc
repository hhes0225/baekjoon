#include <iostream>
#include <string>
using namespace std;

int main() {
    int troom, tcond;
    string mode;
    cin >> troom >> tcond;
    cin >> mode;

    int result;
    if (mode == "freeze") {
        // 냉방 모드: 현재 온도보다 높으면 낮춰야 하지만,
        // troom이 tcond보다 낮거나 같으면 꺼지므로 min
        result = min(troom, tcond);
    }
    else if (mode == "heat") {
        // 난방 모드: 현재 온도보다 낮으면 올려야 하지만,
        // troom이 tcond보다 높거나 같으면 꺼지므로 max
        result = max(troom, tcond);
    }
    else if (mode == "auto") {
        // 자동 모드: 무조건 tcond로 맞춤
        result = tcond;
    }
    else if (mode == "fan") {
        // 송풍 모드: 온도 변화 없음
        result = troom;
    }
    else {
        // 입력 제한상 도달하지 않음
        result = troom;
    }

    cout << result << "\n";
    return 0;
}
