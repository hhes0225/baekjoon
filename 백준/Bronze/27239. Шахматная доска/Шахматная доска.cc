#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // n은 1부터 시작하므로 -1 해서 0부터 계산
    n -= 1;

    // 열은 0~7 → 'a'+열 번호로 문자 계산
    char col = 'a' + (n % 8);

    // 행은 아래서부터 세므로 1~8
    int row = (n / 8) + 1;

    cout << col << row << endl;

    return 0;
}
