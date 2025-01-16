#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C; // 세 개의 정수를 입력받습니다.
    
    if (A + B + C <= 21) {
        cout << 1; // 합이 21 이하일 경우 1 출력
    } else {
        cout << 0; // 그렇지 않을 경우 0 출력
    }
    
    return 0;
}
