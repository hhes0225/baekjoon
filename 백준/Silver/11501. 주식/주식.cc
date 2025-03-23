#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void getMaxAdvantage(vector<int>& stock, int n) {
    int maxPrice = 0;
    long long advantage = 0;
    long long cost = 0;

    // 뒤에서부터 순회하면서 최대값 갱신
    for (int i = n - 1; i >= 0; i--) {
        // 현재 가격보다 높은 가격이 있다면 최대값 갱신
        if (stock[i] > maxPrice) {
            maxPrice = stock[i];
        }
        // 최대값에서 현재 가격을 뺀 만큼 이익
        advantage += maxPrice - stock[i];
    }

    cout << advantage << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> stock(n);

        for (int j = 0; j < n; j++) {
            cin >> stock[j];
        }

        getMaxAdvantage(stock, n);
    }

    return 0;
}
