#include <iostream>

using namespace std;

/*
	boj9295
	오늘은 갑자기 주사위를 던지고 싶다.
	그런데 코딩도 하고 싶다.
	그럼 같이할까?

	입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다.
	각 테스트 케이스는 한 줄로 이루어져 있으며, 주사위를 두 번 던져 나온 두 수를 입력한다.

	출력
	각 테스트 케이스마다 "Case x: "를 출력한 다음, 주사위를 두 번 던져 나온 두 수의 합을 출력한다. 테스트 케이스 번호(x)는 1부터 시작한다.
*/


int main(void) {
	int tCase;
	int try1, try2;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> try1 >> try2;

		cout << "Case " << i+1 << ": " << try1 + try2 << '\n';
	}


	return 0;
}