#include <iostream>

using namespace std;

int main(void) {
	int limit, num;
	int cpy;
	int freq = 0;

	cin >> limit >> num;

	for (int i = 1; i <= limit; i++) {
		cpy = i;
		
		while (1) {
			if (cpy <= 0) {
				break;
			}

			if (cpy % 10 == num) {
				freq++;
			}
			cpy /= 10;
			//cout << cpy << endl;
		}
	}

	cout << freq << '\n';


	return 0;
}