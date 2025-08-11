#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;  // 단위 정사각형의 개수 입력

    int count = 0;
    long long k = 1;  // 첫 번째 정사각형은 1x1 크기부터 시작

    // 가능한 한 많은 정사각형을 만들기
    while (n >= k * k) {
        n -= k * k;  // k^2 만큼의 단위 정사각형을 사용
        count++;      // 하나의 정사각형을 만들었으므로 카운트 증가
        k++;          // 다음 크기의 정사각형으로 이동
    }

    cout << count << endl;  // 만들 수 있는 정사각형의 개수를 출력
    return 0;
}
