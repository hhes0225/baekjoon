#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pebbles;
vector<int> dp; // dp[i] : 0번부터 i번 위치까지 진행하면서 인접연산(1번 연산)으로 줄인 작업 횟수의 최대값

int minTry(int n) {
    // i==0인 경우: dp[0]는 아직 인접연산을 쓸 수 없으므로 0
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        // i가 0보다 크면 이전까지의 절감 횟수를 그대로 전달.
        if(i > 0) dp[i] = max(dp[i], dp[i - 1]);
        
        int remain = pebbles[i];
        // i 위치부터 오른쪽으로 확장하면서 인접연산으로 제거할 수 있는 구간을 찾는다.
        for (int j = i + 1; j < n; j++) {
            remain = pebbles[j] - remain;
            if (remain < 0)
                break; // 더 이상 연산으로 맞출 수 없으면 종료
            if (remain == 0) {
                // i~j 구간을 인접연산 하나로 제거할 수 있다.
                int candidate = (i - 1 >= 0 ? dp[i - 1] : 0) + 1;
                dp[j] = max(dp[j], candidate);
                break; // 한번 제거하면 그 구간은 처리한 것으로 보고 종료
            }
        }
    }
    
    // 기본 작업 횟수는 각 위치마다 제거(총 n번)이고, dp[n-1]만큼 줄일 수 있음.
    return n - dp[n - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    pebbles.resize(n);
    dp.assign(n, 0);
    
    for (auto &p : pebbles) {
        cin >> p;
    }
    
    cout << minTry(n) << "\n";
    
    return 0;
}
