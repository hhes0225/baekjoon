#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int even = 0, odd = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0)
            ++even;
        else
            ++odd;
    }

    cout << 1LL * even * odd << '\n'; // long long형으로 오버플로우 방지
    return 0;
}
