#include <iostream>
#include <string>
using namespace std;

int main() {
    string k;
    cin >> k;

    // 문자열 뒤에서부터 끝의 '0' 제거
    while (!k.empty() && k.back() == '0') {
        k.pop_back();
    }

    // 남은 문자열에서 '0' 개수 세기
    int count = 0;
    for (char c : k) {
        if (c == '0') count++;
    }

    cout << count << endl;
    return 0;
}
