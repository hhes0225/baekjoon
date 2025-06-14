#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;

    long long g = k / 5;      // 완전한 5회 구간 수
    long long r = k % 5;      // 나머지 누른 횟수

    // 공식 적용
    long long result = 75LL * g * (g + 1)
                     + 30LL * r * (g + 1);

    cout << result << "\n";
    return 0;
}
