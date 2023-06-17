#include <iostream>

using namespace std;

int main(void) {
	int totalCost;
	int sum = 0;
	int tmp;
	int unreadable;

	cin >> totalCost;

	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		sum += tmp;
	}

	cout << totalCost - sum << endl;


	return 0;
}