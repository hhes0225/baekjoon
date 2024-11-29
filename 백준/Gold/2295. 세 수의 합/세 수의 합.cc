#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    unordered_set<int> num_set;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        num_set.insert(nums[i]);
    }

    sort(nums.begin(), nums.end()); // 정렬 필수

    int ans = 0;

    // 두 수의 합을 모두 계산하여 저장합니다.
    vector<int> sum_two;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum_two.push_back(nums[i] + nums[j]);
        }
    }

    // 두 수의 합을 정렬합니다.
    sort(sum_two.begin(), sum_two.end());

    // 가장 큰 수부터 탐색합니다.
    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            int diff = nums[k] - nums[i];
            // 두 수의 합 중에 diff가 있는지 이진 탐색합니다.
            if (binary_search(sum_two.begin(), sum_two.end(), diff)) {
                cout << nums[k] << "\n";
                return 0;
            }
        }
    }

    return 0; // 문제의 조건상 항상 답이 존재하므로 여기에 도달하지 않습니다.
}
