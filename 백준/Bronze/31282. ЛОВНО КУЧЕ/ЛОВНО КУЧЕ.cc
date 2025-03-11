#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    // (K - M)로 나누어떨어지지 않으면 올림 처리
    int jumps = (N + (K - M - 1)) / (K - M);

    cout << jumps << "\n";
    return 0;
}
