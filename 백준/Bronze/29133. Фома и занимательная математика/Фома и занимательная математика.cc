#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    int answer = -1;

    for (int x = 1; x <= 3; ++x) {
        ll sum = 0;
        // 각각의 a, b, c를 x제곱한 값을 더함
        ll aa = 1, bb = 1, cc = 1;
        for (int i = 0; i < x; ++i) {
            aa *= a;
            bb *= b;
            cc *= c;
        }
        sum = aa + bb + cc;

        if (sum == d) {
            if (answer == -1) {
                answer = x;
            } else {
                // 이미 정답이 있는데 또 나오면 x를 결정할 수 없으니 -1
                answer = -1;
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
