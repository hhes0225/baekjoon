#include <iostream>
#include <string>

using namespace std;

/*
	boj27866
	단어 S와 정수 i가 주어졌을 때, S의 i번째 글자를 출력하는 프로그램을 작성하시오.
*/

int main(void) {
	string s;
	int i;

	cin >> s >> i;

	cout << s[i - 1]<<'\n';
}