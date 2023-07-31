#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string sample;
	int tCase;
	string ring;
	int freq = 0;

	cin >> sample;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> ring;

		string circle = ring + ring;

		//cout << circle << endl;

		if (ring.find(sample) != string::npos) {//찾고자 하는 문자열이 있으면
			freq++;
		}
		else if (circle.find(sample) != string::npos) {//처음과 끝을 이었을 때의 문자열이 있으면
			freq++;
		}
		else {
			continue;
		}
	}

	cout << freq << '\n';

	return 0;
}