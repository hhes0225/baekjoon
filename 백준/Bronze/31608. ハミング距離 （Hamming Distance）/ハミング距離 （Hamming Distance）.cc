#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S, T;
    
    cin >> N >> S >> T;

    int hamming = 0;

    // 같은 인덱스의 문자 비교
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[i]) {
            hamming++;
        }
    }

    cout << hamming << '\n';

    return 0;
}
