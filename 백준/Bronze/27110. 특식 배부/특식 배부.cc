#include <iostream>

using namespace std;

/*
	boj27110

*/

int main(void) {
	int order;
	int fried, spicy, soy;
	int taste;

	cin >> order;
	cin >> fried >> spicy >> soy;

	if (order < fried) {
		fried = order;
	}
	if (order < spicy) {
		spicy = order;
	}
	if (order < soy) {
		soy = order;
	}

	taste = fried + spicy + soy;

	cout << taste;

	return 0;
}