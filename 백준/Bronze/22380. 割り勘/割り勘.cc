#include <iostream>
using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        int A[100];
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int payPerPerson = M / N;
        int total = 0;

        for (int i = 0; i < N; ++i) {
            // 각 사람은 최대 payPerPerson까지만 부담할 수 있고, 그보다 적으면 전액 내도록 함
            total += min(A[i], payPerPerson);
        }

        cout << total << endl;
    }

    return 0;
}
