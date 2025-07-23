#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N, M;
    cin >> K;

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    int count = 0;

    // 모든 (p, q) 쌍에 대해 검사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i] + K == B[j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
