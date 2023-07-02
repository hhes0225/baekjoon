#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int tCase;
	int student, apple;
	int tmp;
	vector<int> spareApple;
	int sum = 0;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> student >> apple;

		tmp = apple % student;
		sum += tmp;
	}

	cout << sum << '\n';

	return 0;
}