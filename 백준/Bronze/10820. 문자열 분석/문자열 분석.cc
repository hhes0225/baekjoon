#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	int upper = 0, lower = 0, space = 0, num = 0;

	/*cout << (int)'0' << " " << (int)'9' << endl;
	cout << (int)'a' << " " << (int)'z' << endl;
	cout << (int)'A' << " " << (int)'Z' << endl;
	cout << (int)' ' << endl;*/

	while (getline(cin, input)) {
		upper = 0;
		lower = 0;
		space = 0;
		num = 0;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ') {
				space++;
			}
			else if (input[i] >= '0' && input[i] <= '9') {
				num++;
			}
			else if (input[i] >= 'a' && input[i] <= 'z') {
				lower++;
			}
			else if (input[i] >= 'A' && input[i] <= 'Z') {
				upper++;
			}
		}

		cout << lower << ' ' << upper << ' ' << num << ' ' << space << '\n';
	}


	return 0;
}