#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 키패드 좌표 정의
pair<int, int> getCoord(char ch) {
    switch (ch) {
        case '1': return {0, 0};
        case '2': return {1, 0};
        case '3': return {2, 0};
        case '4': return {0, 1};
        case '5': return {1, 1};
        case '6': return {2, 1};
        case '7': return {0, 2};
        case '8': return {1, 2};
        case '9': return {2, 2};
        case '0': return {1, 3};
        default: return {-1, -1};
    }
}

int main() {
    string input;
    cin >> input;

    // 숫자가 3개가 아니면 Locked
    if (input.size() != 3) {
        cout << "Locked" << endl;
        return 0;
    }

    // 서로 다른 숫자인지 확인
    if (input[0] == input[1] || input[0] == input[2] || input[1] == input[2]) {
        cout << "Locked" << endl;
        return 0;
    }

    // 좌표 가져오기
    vector<pair<int, int>> coords;
    for (char ch : input) {
        coords.push_back(getCoord(ch));
    }

    // 정렬 (수평 또는 수직 확인을 쉽게 하기 위함)
    sort(coords.begin(), coords.end());

    // 수평 확인 (y가 같고 x가 연속)
    bool horizontal = (coords[0].second == coords[1].second &&
                       coords[1].second == coords[2].second &&
                       coords[0].first + 1 == coords[1].first &&
                       coords[1].first + 1 == coords[2].first);

    // 수직 확인 (x가 같고 y가 연속)
    bool vertical = (coords[0].first == coords[1].first &&
                     coords[1].first == coords[2].first &&
                     coords[0].second + 1 == coords[1].second &&
                     coords[1].second + 1 == coords[2].second);

    if (horizontal || vertical) {
        cout << "Unlocked" << endl;
    } else {
        cout << "Locked" << endl;
    }

    return 0;
}
