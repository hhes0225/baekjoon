#include <iostream>
using namespace std;

int main() {
    int a1, b1, c1; // 첫 번째 시간 기준 (시, 분, 초의 구조)
    int a2, b2, c2; // 두 번째 시간 기준
    int h1, m1, s1; // 첫 번째 기준 시간

    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> h1 >> m1 >> s1;

    // 1단계: 첫 번째 기준의 시간을 초로 환산
    long long total_seconds = (long long)h1 * b1 * c1 + (long long)m1 * c1 + s1;

    // 2단계: 두 번째 기준에 맞춰 다시 시/분/초로 환산
    int h2 = total_seconds / (b2 * c2);
    total_seconds %= (b2 * c2);

    int m2 = total_seconds / c2;
    int s2 = total_seconds % c2;

    cout << h2 << " " << m2 << " " << s2 << endl;
    return 0;
}
