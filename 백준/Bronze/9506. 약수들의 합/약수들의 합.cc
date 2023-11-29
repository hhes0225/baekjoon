#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj9506
	어떤 숫자 n이 자신을 제외한 모든 약수들의 합과 같으면, 그 수를 완전수라고 한다.

	예를 들어 6은 6 = 1 + 2 + 3 으로 완전수이다.

	n이 완전수인지 아닌지 판단해주는 프로그램을 작성하라.
*/

int main(void) {
	int input;
	vector<int> divisor;
	int sum = 0;

	while (1) {
		divisor.clear();
		sum = 0;
		cin >> input;

		if (input == -1)
			break;

		for (int i = 1; i < input; i++) {
			if (input % i == 0) {
				divisor.push_back(i);
				sum += i;
			}
		}
		
		sort(divisor.begin(), divisor.end());

		if (sum != input) {
			cout << input << " is NOT perfect.\n";
		}
		else {
			cout << input << " =";

			for (int i = 0; i < divisor.size(); i++) {
				if (i == divisor.size() - 1) {
					cout << " " << divisor[i];
				}
				else {
					cout << " " << divisor[i] << " +";
				}
			}

			cout << '\n';
		}

	}

	return 0;
}