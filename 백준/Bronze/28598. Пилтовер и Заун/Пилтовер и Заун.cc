#include <iostream>
using namespace std;

int main() {
    long long x1, x2, n;
    cin >> x1 >> x2 >> n;

    if (n == 0) {
        if (x1 == x2) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }

    long long diff = x1 - x2;
    if (diff % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    long long sum = diff / 2;
    if (sum >= n) cout << "YES\n";
    else cout << "NO\n";
}
