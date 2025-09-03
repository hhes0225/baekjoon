
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> top_numbers, bottom_numbers;
    
    // 위쪽 행 입력 (0이 아닌 숫자만 저장)
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            top_numbers.push_back(x);
        }
    }
    
    // 아래쪽 행 입력 (0이 아닌 숫자만 저장)
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            bottom_numbers.push_back(x);
        }
    }
    
    int top_len = top_numbers.size();
    int bottom_len = bottom_numbers.size();
    
    // 메모리 최적화: 2차원 배열만 사용 (이전 열과 현재 열)
    vector<vector<long long>> prev(top_len + 1, vector<long long>(bottom_len + 1, LLONG_MIN));
    vector<vector<long long>> curr(top_len + 1, vector<long long>(bottom_len + 1, LLONG_MIN));
    
    // 초기 상태
    prev[0][0] = 0;
    
    // 각 열에 대해 처리
    for (int col = 0; col < N; col++) {
        // curr 배열 초기화
        for (int i = 0; i <= top_len; i++) {
            for (int j = 0; j <= bottom_len; j++) {
                curr[i][j] = LLONG_MIN;
            }
        }
        
        for (int i = 0; i <= top_len; i++) {
            for (int j = 0; j <= bottom_len; j++) {
                if (prev[i][j] == LLONG_MIN) continue;
                
                long long curr_value = prev[i][j];
                
                // 경우 1: 둘 다 빈칸
                curr[i][j] = max(curr[i][j], curr_value);
                
                // 경우 2: 위쪽만 숫자 배치
                if (i < top_len) {
                    curr[i + 1][j] = max(curr[i + 1][j], curr_value);
                }
                
                // 경우 3: 아래쪽만 숫자 배치
                if (j < bottom_len) {
                    curr[i][j + 1] = max(curr[i][j + 1], curr_value);
                }
                
                // 경우 4: 둘 다 숫자 배치
                if (i < top_len && j < bottom_len) {
                    long long product = (long long)top_numbers[i] * bottom_numbers[j];
                    curr[i + 1][j + 1] = max(curr[i + 1][j + 1], curr_value + product);
                }
            }
        }
        
        // prev = curr로 업데이트
        prev = curr;
    }
    
    // 모든 숫자를 사용한 상태에서의 최대값 출력
    cout << prev[top_len][bottom_len] << endl;
    
    return 0;
}