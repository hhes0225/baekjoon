#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int tCase;
	int tmp;
	vector<int> nums;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	return 0;
}