#include <iostream>
#include <string>

using namespace std;

/*
	boj11170
	N부터 M까지의 수들을 종이에 적었을 때 종이에 적힌 0들을 세는 프로그램을 작성하라.
	예를 들어, N, M이 각각 0, 10일 때 0을 세면 0에 하나, 10에 하나가 있으므로 답은 2이다.
*/

int main(void) {
	int tCase;
	int from, to;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> from >> to;
		int zero = 0;

		for (int j = from; j <= to; j++) {
			string tmp = to_string(j);
			
			for (int k = 0; k < tmp.size(); k++) {
				if (tmp[k] == '0') {
					zero++;
				}
			}
			
		}
		cout << zero << endl;
	}

	return 0;
}