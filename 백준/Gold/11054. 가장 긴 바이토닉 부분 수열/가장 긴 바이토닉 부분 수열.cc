#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> LIS(N, 1);  // 정방향 LIS
    vector<int> LDS(N, 1);  // 역방향 LIS

    // 정방향 LIS 계산 (왼쪽에서 오른쪽으로)
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    // 역방향 LIS 계산 (오른쪽에서 왼쪽으로)
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[i]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    // 바이토닉 수열의 최대 길이 구하기
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, LIS[i] + LDS[i] - 1);
    }

    cout << maxLength << endl;

    return 0;
}
