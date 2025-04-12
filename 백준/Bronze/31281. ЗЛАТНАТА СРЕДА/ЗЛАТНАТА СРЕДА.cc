#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    vector<long long> nums = {a, b, c};
    sort(nums.begin(), nums.end());  // 오름차순 정렬

    cout << nums[1] << endl;  // 중간값 출력

    return 0;
}
