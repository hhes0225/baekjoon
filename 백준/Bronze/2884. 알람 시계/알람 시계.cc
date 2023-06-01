#include <iostream>

using namespace std;

int main(void) {
	int hour, minute;

	cin >> hour >> minute;

	if (minute - 45 >= 0) {
		minute -= 45;
	}
	else {
		minute = minute + 60 - 45;
		hour--;

		if (hour < 0) {
			hour += 24;
		}
	}

	cout << hour << " " << minute << endl;


	return 0;
}