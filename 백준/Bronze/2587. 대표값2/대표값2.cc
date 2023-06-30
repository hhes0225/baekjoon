#include <iostream>
#include <vector>
#include <algorithm>
#define tCase 5

using namespace std;

int main(void) {
	int tmp;
	vector<int> numbers;
	int average = 0;
	int center;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
		average += tmp;
	}

	sort(numbers.begin(), numbers.end());

	average /= tCase;

	cout << average << '\n' << numbers[2] << '\n';




	return 0;
}