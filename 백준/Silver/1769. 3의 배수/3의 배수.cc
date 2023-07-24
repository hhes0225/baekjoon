#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string input;
	long long int sum = 0;
	int step = 0;
	bool divide3 = false;


	cin >> input;

	while (1) {
		//cout << input<<'\n';

		if (input.size() == 1) {
			break;
		}

		step++;
		for (int i = 0; i < input.size(); i++) {
			sum += input[i] - (int)'0';
		}

		/*if (sum % 3 == 0) {
			divide3 = true;
			break;
		}*/

		input = to_string(sum);
		sum = 0;

	}

	if (input.size() == 1) {
		if (stoi(input) % 3 == 0) {
			divide3 = true;
		}
	}

	cout << step << '\n';

	if (divide3) {
		
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}