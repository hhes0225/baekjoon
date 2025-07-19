#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> choco(N);
    for (int i = 0; i < N; ++i) {
        cin >> choco[i];
    }

    int cnt = 0;  // 새 박스를 꺼낸 횟수

    for (int i = 0; i < N - 1; ++i) {
        if (choco[i + 1] > choco[i]) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
