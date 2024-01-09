#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define SIZE 10
#define N 3

int main(void) {
	int tCase;
	vector<int> arr;

	cin >> tCase;

	arr.resize(SIZE);

	for (int i = 0; i < tCase; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> arr[j];
		}

		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());

		cout << arr[N-1] << endl;
	}

	return 0;
}