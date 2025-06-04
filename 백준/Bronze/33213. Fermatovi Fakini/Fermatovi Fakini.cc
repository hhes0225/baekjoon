#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    set<int> odd, even;

    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even.insert(a[i]);
            cnt_even++;
        } else {
            odd.insert(a[i]);
            cnt_odd++;
        }
    }

    bool pick_odd = cnt_odd > cnt_even;
    int x = pick_odd ? 1 : 2;

    while (true) {
        if (pick_odd) {
            if (!odd.count(x)) {
                cout << x << '\n';
                break;
            }
            x += 2;
        } else {
            if (!even.count(x)) {
                cout << x << '\n';
                break;
            }
            x += 2;
        }
    }
    return 0;
}
