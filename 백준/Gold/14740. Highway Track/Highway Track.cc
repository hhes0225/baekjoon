#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> o(N), d(N);
    vector<ll> diff(2 * N), psum(2 * N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> o[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }

    // 원본 diff 계산
    for (int i = 0; i < N; ++i) {
        diff[i] = o[i] - d[i];
    }
    // 원형으로 2배 확장
    for (int i = 0; i < N; ++i) {
        diff[i + N] = diff[i];
    }

    // 누적합 psum: psum[i] = diff[0] + ... + diff[i-1]
    for (int i = 0; i < 2 * N; ++i) {
        psum[i + 1] = psum[i] + diff[i];
    }

    int ans = 0;
    deque<int> dq;

    // i는 psum 인덱스, 1부터 (2N - 1)까지 순회
    // i == s + k 때 psum[i]는 "시작점 s에서 k칸 이동했을 때의 누적합 + psum[s]"
    // 윈도우 크기 N으로, i >= N인 경우에만 "시작점 s = i - N"을 검사
    for (int i = 1; i <= 2 * N - 1; ++i) {
        // 윈도우 범위: [i - N + 1, i]
        // 이 인덱스가 psum상 [s+1, s+N] = [i-N+1, i]
        // 슬라이딩 윈도우에서 범위를 벗어난 맨 앞 인덱스 제거
        while (!dq.empty() && dq.front() < i - N + 1) {
            dq.pop_front();
        }
        // 새로 들어온 psum[i]가 뒤에 있는 인덱스의 psum 값보다 작거나 같으면 제거
        while (!dq.empty() && psum[dq.back()] >= psum[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // i >= N 일 때부터 "시작점 s = i - N"을 검사
        if (i >= N) {
            int s = i - N;
            // s가 0..N-1 범위여야 valid
            // dq.front()는 지금 윈도우 [s+1, s+N]의 최소 psum 인덱스를 가리킴
            if (psum[dq.front()] >= psum[s]) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
