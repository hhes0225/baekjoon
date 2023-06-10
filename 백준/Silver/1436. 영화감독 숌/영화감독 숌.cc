#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int input;
	int normalSeries=0;
	int series666=666;

	cin >> input;

	while (input != normalSeries) {
		if (to_string(series666).find("666") != string::npos) {
			normalSeries++;
		}

		series666++;
	}

	cout << --series666 << endl;


	return 0;
}