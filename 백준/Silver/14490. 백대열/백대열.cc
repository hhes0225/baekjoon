#include <iostream>
#include <string>

using namespace std;

//n과 m이 : 을 사이에 두고 주어진다. (1 ≤ n, m ≤ 100, 000, 000)
//두 수를 최대한으로 약분하여 출력한다.
//즉, 문자열로 입력받아서 :를 중심으로 숫자를 split 하고
//그 다음으로 두 수의 최대공약수 GCD를 구하라

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
