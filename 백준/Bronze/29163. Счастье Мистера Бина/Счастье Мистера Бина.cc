#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, even_count = 0, odd_count = 0;  // 변수 선언 (짝수, 홀수 카운트)
    cin >> n;  // 숫자의 개수 입력

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;  // 숫자 입력

        if (num % 2 == 0) // 짝수인지 확인
            even_count++;
        else
            odd_count++;
    }

    // 짝수가 많으면 "Happy", 그렇지 않으면 "Sad" 출력
    cout << (even_count > odd_count ? "Happy" : "Sad") << endl;

    return 0;
}
