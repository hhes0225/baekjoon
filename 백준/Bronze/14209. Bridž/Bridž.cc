#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int totalPoints = 0;

    while (N--) {
        string cards;
        cin >> cards;

        for (char c : cards) {
            switch (c) {
                case 'A': totalPoints += 4; break;
                case 'K': totalPoints += 3; break;
                case 'Q': totalPoints += 2; break;
                case 'J': totalPoints += 1; break;
                case 'X': break; // 점수 없음
            }
        }
    }

    cout << totalPoints << endl;
    return 0;
}
