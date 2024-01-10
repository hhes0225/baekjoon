#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	string mobis = "MOBIS";
	bool ismobis = true;

	cin >> input;

	for (int i = 0; i < mobis.size(); i++) {
		if (input.find(mobis[i]) != string::npos) {
			continue;
		}
		else {
			//cout << mobis[i] << endl;
			ismobis = false;
		}

	}

	if (ismobis) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}