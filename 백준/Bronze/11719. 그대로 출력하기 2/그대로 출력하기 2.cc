#include <iostream>
#include <string>

using namespace std;

/*
	boj11719

	입력 받은 대로 출력하는 프로그램을 작성하시오.
*/

int main(void) {
	string input;

	while (getline(cin, input)) {
		cout << input << "\n";
	}

	return 0;
}