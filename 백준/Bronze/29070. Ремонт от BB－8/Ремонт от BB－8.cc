#include <iostream>
using namespace std;

int main() {
    int a, b, h, w;
    cin >> a >> b >> h >> w;

    // 세로로 필요한 플레이트 개수 = h / a 올림
    int vertical = (h + a - 1) / a;
    // 가로로 필요한 플레이트 개수 = w / b 올림
    int horizontal = (w + b - 1) / b;

    // 총 개수는 세로 * 가로
    cout << vertical * horizontal << endl;

    return 0;
}
