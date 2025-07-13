#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    int aoi_win = 0;     // 아오이가 이긴 횟수
    int bitaro_win = 0;  // 비타로가 이긴 횟수

    for (int i = 0; i < N; ++i) {
        char aoi = S[i];     // 아오이의 선택 (R 또는 S)
        char bitaro = T[i];  // 비타로의 선택 (R 또는 P)

        // 아오이: R(바위), S(가위)
        // 비타로: R(바위), P(보)

        // 아오이가 이기는 경우: S(가위) vs P(보)
        if (aoi == 'S' && bitaro == 'P') {
            aoi_win++;
        }
        // 비타로가 이기는 경우: R(바위) vs P(보)
        else if (aoi == 'R' && bitaro == 'P') {
            bitaro_win++;
        }
        // 비타로가 이기는 경우: S(가위) vs R(바위)
        else if (aoi == 'S' && bitaro == 'R') {
            bitaro_win++;
        }
        // 나머지는 무승부 (R-R)
    }

    // 결과 출력
    cout << aoi_win << " " << bitaro_win << endl;
    return 0;
}
