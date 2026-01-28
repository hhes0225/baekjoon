#include <iostream>
#include <vector>
#include <algorithm> // max 함수 사용

using namespace std;

int main() {
    // 입출력 속도 향상 (알고리즘 문제 풀이 필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 밝기 배열 A 입력 받기
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 상태 배열 B 입력 받으면서 기본 점수 및 변화량 계산
    vector<int> diff(N);
    long long original_sum = 0; // 현재 켜져 있는 전구들의 밝기 합

    for (int i = 0; i < N; i++) {
        int state;
        cin >> state;

        if (state == 1) {
            // 이미 켜져 있는 경우
            original_sum += A[i];  // 기본 점수에 추가
            diff[i] = -A[i];       // 뒤집으면 꺼지므로 손해(-)
        } else {
            // 꺼져 있는 경우
            diff[i] = A[i];        // 뒤집으면 켜지므로 이득(+)
        }
    }

    // 카데인 알고리즘 (연속 부분 합의 최댓값 구하기)
    // 반드시 하나 이상 뒤집어야 하므로 첫 번째 값으로 초기화
    long long current_sum = diff[0];
    long long max_diff = diff[0];

    for (int i = 1; i < N; i++) {
        // (지금 값부터 새로 시작) vs (앞의 합에 이어 붙이기) 중 큰 것 선택
        current_sum = max((long long)diff[i], current_sum + diff[i]);
        
        // 전체 최댓값 갱신
        max_diff = max(max_diff, current_sum);
    }

    // 최종 정답 출력: (기본 점수) + (최대 변화량)
    cout << original_sum + max_diff << "\n";

    return 0;
}