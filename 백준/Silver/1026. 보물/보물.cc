#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj1026
	옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

	길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

	S = A[0] × B[0] + ... + A[N-1] × B[N-1]

	S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

	S의 최솟값을 출력하는 프로그램을 작성하시오.

	============================

	접근법: S의 최소값을 만들기 위해서는 A의 최소값과 B의 최대값, 혹은 vice versa를 해주면 최소값을 구할 수 있다.
	중요조건: 배열 B를 건드리지 말아라, 재배열하지 말아라

	해결법: 그럼 배열 A의 최소값과 배열 B의 최대값을 구해서 곱하고, S에 더한다.
		그 뒤에 해당 배열 A, 배열 B에서 사용된 값을 삭제한다
*/

int length;
vector<int> A;
vector<int> B;
int S = 0;

void getMinS() {
	vector<int> copyA, copyB;

	copyA = A;
	copyB = B;

	for (int i = 0; i < length; i++) {
		int minA=999999;
		int maxB=0;

		for (int i = 0; i < copyA.size(); i++) {
			minA = min(minA, copyA[i]);
		}

		copyA.erase(find(copyA.begin(), copyA.end(), minA));

		for (int i = 0; i < copyB.size(); i++) {
			maxB = max(maxB, copyB[i]);
		}

		copyB.erase(find(copyB.begin(), copyB.end(), maxB));

		S += minA * maxB;

		
	}



}

int main(void) {
	cin >> length;

	A.resize(length);
	B.resize(length);

	for (int i = 0; i < length; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < length; i++) {
		cin >> B[i];
	}

	getMinS();

	cout << S << endl;

	return 0;
}