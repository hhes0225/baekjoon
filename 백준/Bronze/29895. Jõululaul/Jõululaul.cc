#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;            // N 도 큰 곱을 위해 64비트로
    cin >> N;

    for (long long i = 1; i <= N; i++) {
        // long long 곱을 보장
        cout << i * (N - i + 1) << '\n';
    }
    return 0;
}
