#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> bills(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> bills[i];
        sum += bills[i];
    }

    int min_bill = *min_element(bills.begin(), bills.end());

    if (sum - min_bill >= k)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
