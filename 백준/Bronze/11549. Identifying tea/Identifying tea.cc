#include <iostream>

using namespace std;

int main(void) {
	int answer;
	int a, b, c, d, e;
	int correct = 0;

	cin >> answer;

	cin >> a >> b >> c >> d >> e;

	if(a==answer){
		correct++;
	}
	if (b == answer) {
		correct++;
	}
	if (c == answer) {
		correct++;
	}
	if (d == answer) {
		correct++;
	}
	if (e == answer) {
		correct++;
	}

	cout << correct << endl;
}