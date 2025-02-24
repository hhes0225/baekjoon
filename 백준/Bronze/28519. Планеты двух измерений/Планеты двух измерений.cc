#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // 두 차원의 행성 개수를 입력받음
    long long n, m;
    cin >> n >> m;
    
    long long ans;
    if(n == m) {
        // 두 차원의 행성 수가 같다면 모든 행성을 방문할 수 있음
        ans = n + m;
    } else {
        // 한쪽 차원의 행성이 더 많을 경우, 번갈아 방문 후 추가로 한 개 방문 가능
        ans = 2 * min(n, m) + 1;
    }
    
    cout << ans << endl;
    return 0;
}
