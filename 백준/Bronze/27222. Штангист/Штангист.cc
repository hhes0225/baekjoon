#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // 각 날짜에 대해 훈련 여부를 저장할 배열
    int training[1001];
    for (int i = 0; i < n; i++) {
        cin >> training[i];
    }
    
    long long totalGain = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        // 훈련을 했고, 체중이 증가한 경우에만 증가량을 더한다.
        if (training[i] == 1 && y > x) {
            totalGain += (y - x);
        }
    }
    
    cout << totalGain;
    return 0;
}
