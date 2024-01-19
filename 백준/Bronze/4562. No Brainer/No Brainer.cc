#include <iostream>
using namespace std;

int main(void) {
	int tCase;
	int x;//zombie eat
	int y;//num of brain zombie requires to stay alive

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> x >> y;

		if (x < y) {
			cout << "NO BRAINS" << endl;
		}
		else {
			cout << "MMM BRAINS" << endl;
		}
	}

	return 0;
}