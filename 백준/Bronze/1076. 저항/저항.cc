#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string input;
	vector<long long int> resistance;
	long long int result;

	for (int i = 0; i < 3; i++) {
		cin >> input;

		if (i < 2) {
			if (input == "black") {
				resistance.push_back(0);
			}
			else if (input == "brown") {
				resistance.push_back(1);
			}
			else if (input == "red") {
				resistance.push_back(2);
			}
			else if (input == "orange") {
				resistance.push_back(3);
			}
			else if (input == "yellow") {
				resistance.push_back(4);
			}
			else if (input == "green") {
				resistance.push_back(5);
			}
			else if (input == "blue") {
				resistance.push_back(6);
			}
			else if (input == "violet") {
				resistance.push_back(7);
			}
			else if (input == "grey") {
				resistance.push_back(8);
			}
			else if (input == "white") {
				resistance.push_back(9);
			}
		}
		else {
			if (input == "black") {
				resistance.push_back(1);
			}
			else if (input == "brown") {
				resistance.push_back(10);
			}
			else if (input == "red") {
				resistance.push_back(100);
			}
			else if (input == "orange") {
				resistance.push_back(1000);
			}
			else if (input == "yellow") {
				resistance.push_back(10000);
			}
			else if (input == "green") {
				resistance.push_back(100000);
			}
			else if (input == "blue") {
				resistance.push_back(1000000);
			}
			else if (input == "violet") {
				resistance.push_back(10000000);
			}
			else if (input == "grey") {
				resistance.push_back(100000000);
			}
			else if (input == "white") {
				resistance.push_back(1000000000);
			}
		}
	}

	result = (resistance[0] * 10 + resistance[1]) * resistance[2];

	cout << result << '\n';


	return 0;
}