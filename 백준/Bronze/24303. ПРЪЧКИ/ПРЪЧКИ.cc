#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a1, a2, a3;
    int b1, b2, b3;
    int L;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> L;

    int minSticks = 1e9; // 매우 큰 수로 초기화

    for(int x = 0; x <= b1; x++) {
        for(int y = 0; y <= b2; y++) {
            for(int z = 0; z <= b3; z++) {
                int totalLength = x * a1 + y * a2 + z * a3;
                if(totalLength >= L) {
                    minSticks = min(minSticks, x + y + z);
                }
            }
        }
    }

    if(minSticks == 1e9) cout << "0\n";
    else cout << minSticks << "\n";

    return 0;
}
