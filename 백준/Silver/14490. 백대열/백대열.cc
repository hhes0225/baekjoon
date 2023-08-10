#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	int frontNum, backNum;
	int gcd;
	int bigger;

	cin >> input;

	//cout << input.substr(0, input.find(":")) << '\n';
	frontNum = stoi(input.substr(0, input.find(":")));

	backNum = stoi(input.substr(input.find(":")+1, input.size()));
	//cout << backNum << endl;

	bigger = max(frontNum, backNum);

	for (int i = 1; i <= bigger; i++) {
		if (frontNum % i == 0 && backNum % i == 0) {
			gcd = i;
		}
	}

	cout << frontNum / gcd << ":" << backNum / gcd << "\n";

	return 0;
}