#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // 줄의 개수 n 입력
    
    for (int i = 1; i <= n; i++) {
        int stars = i * i;  // k번째 줄에는 k^2개의 별이 필요
        
        if (stars > 100) {
            // 별이 100개를 초과하면 100개만 출력하고 '...' 출력
            for (int j = 0; j < 100; j++) {
                cout << "*";
            }
            cout << "...\n";
        } else {
            // 별이 100개 이하이면 해당 개수만큼 별을 출력
            for (int j = 0; j < stars; j++) {
                cout << "*";
            }
            cout << "\n";
        }
    }

    return 0;
}
