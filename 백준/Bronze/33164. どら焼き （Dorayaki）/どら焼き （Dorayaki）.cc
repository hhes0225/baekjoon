#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> B[j];
    }

    long long total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long sum = A[i] + B[j];
            long long mx  = max(A[i], B[j]);
            total += sum * mx;
        }
    }

    cout << total << "\n";
    return 0;
}
