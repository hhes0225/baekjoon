#include<iostream>
#include <string>

using namespace std;

/*
	짝이 없는 경재는 매일 홀로 있다보니 홀수를 판별할 수 있는 능력이 생겼다. 
	창식이는 경재의 말이 사실인지 그 능력을 시험해보려 한다. 
	창식이의 의심이 끝이 없을 것 같아 N개만 확인하기로 정했다.

	N개의 정수가 주어지면 홀수인지 짝수인지를 출력하는 프로그램을 만들어 경재의 능력을 검증할 수 있게 도와주자.
*/

int main(void) {
	int tCase;
	string input;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		if (((int)input[input.size()-1]-(int)'0') % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}

	return 0;
}