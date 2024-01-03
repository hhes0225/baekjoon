#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> nums;
	int from, to;

	for (int i = 1; i <= 20; i++) {
		nums.push_back(i);
	}

	for (int i = 0; i < 10; i++) {
		cin >> from >> to;

		reverse(nums.begin() + from - 1, nums.begin() + to);
	}

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	cout << endl;

	return 0;
}