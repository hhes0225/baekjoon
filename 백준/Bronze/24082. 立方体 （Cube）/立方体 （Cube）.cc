#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X; // 입력받은 한 변의 길이 X

    long long volume = static_cast<long long>(X) * X * X; // 부동소수점 오버플로 방지
    cout << volume << endl; // 체적 출력

    return 0;
}
