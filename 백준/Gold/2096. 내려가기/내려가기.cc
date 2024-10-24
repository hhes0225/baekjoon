#include <iostream>
#include <algorithm>
using namespace std;

const int WIDTH = 3;
const int MAX = 2; // 현재와 이전 값만 필요하므로 크기를 2로 설정

int len;
int dp[2][WIDTH]; // dp[0]: 이전 행, dp[1]: 현재 행
int input[WIDTH];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> len;

    // 최대, 최소 값을 각각 따로 관리
    int max_dp[2][WIDTH] = {0};
    int min_dp[2][WIDTH] = {0};

    // 첫 번째 줄 입력 및 초기화
    cin >> input[0] >> input[1] >> input[2];
    for(int i = 0; i < WIDTH; i++) {
        max_dp[0][i] = min_dp[0][i] = input[i];
    }

    for(int i = 1; i < len; i++) {
        cin >> input[0] >> input[1] >> input[2];

        // 최대값 계산
        max_dp[1][0] = input[0] + max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = input[1] + max({max_dp[0][0], max_dp[0][1], max_dp[0][2]});
        max_dp[1][2] = input[2] + max(max_dp[0][1], max_dp[0][2]);

        // 최소값 계산
        min_dp[1][0] = input[0] + min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = input[1] + min({min_dp[0][0], min_dp[0][1], min_dp[0][2]});
        min_dp[1][2] = input[2] + min(min_dp[0][1], min_dp[0][2]);

        // dp 배열 갱신 (현재 값을 이전 값으로 복사)
        for(int j = 0; j < WIDTH; j++) {
            max_dp[0][j] = max_dp[1][j];
            min_dp[0][j] = min_dp[1][j];
        }
    }

    int max_result = max({max_dp[0][0], max_dp[0][1], max_dp[0][2]});
    int min_result = min({min_dp[0][0], min_dp[0][1], min_dp[0][2]});

    cout << max_result << " " << min_result << "\n";

    return 0;
}
