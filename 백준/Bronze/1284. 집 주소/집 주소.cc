#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int num;

	while (1) {
		int width = 1;
		cin >> num;

		if (num == 0)
			break;

		string strNum = to_string(num);

		for (int i = 0; i < strNum.size(); i++) {
			if (strNum[i] == '0') {
				width += 4;
			}
			else if (strNum[i] == '1') {
				width += 2;
			}
			else {
				width += 3;
			}

			width++;
		}

		cout << width << endl;
	}


	return 0;
}