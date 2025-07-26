#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// hh:mm:ss -> 초 단위 변환
int toSeconds(const string& t) {
    int h, m, s; char c;
    stringstream ss(t);
    ss >> h >> c >> m >> c >> s;
    return h * 3600 + m * 60 + s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string S, F;
        int k;
        cin >> S >> F >> k;

        int start = toSeconds(S);
        int end   = toSeconds(F);

        // 시험이 자정을 넘기거나, S == F 인 경우 모두 24시간 추가
        if (end <= start) {
            end += 24 * 3600;
        }

        int duration    = end - start;        // 시험 시간(초)
        int requiredSec = k * 60;             // Igor가 필요한 시간(초)
        int testLimit   = duration + 3600;    // 시험 종료 후 1시간까지 허용

        if (requiredSec <= duration) {
            cout << "Perfect\n";
        }
        else if (requiredSec <= testLimit) {
            cout << "Test\n";
        }
        else {
            cout << "Fail\n";
        }
    }
    return 0;
}
