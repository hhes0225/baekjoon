#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int tCase;
	vector<int> arr;
	int diff;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int input;
		
		cin >> input;

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	diff = abs(arr[0] - arr[arr.size() - 1]);

	cout << diff << endl;

	return 0;
}