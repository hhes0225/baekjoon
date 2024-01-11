#include <iostream>

using namespace std;

int main(void) {
	int problem, unionLevel, maxLevel;

	cin >> problem >> unionLevel >> maxLevel;

	if (problem >= 1000 && (unionLevel >= 8000 || maxLevel >= 260)) {
		cout << "Very Good" << endl;
	}
	else if (problem >= 1000) {
		cout << "Good" << endl;
	}
	else {
		cout << "Bad" << endl;
	}

	return 0;
}