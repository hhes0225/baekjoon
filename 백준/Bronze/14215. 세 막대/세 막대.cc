#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	boj14215
	영선이는 길이가 a, b, c인 세 막대를 가지고 있고, 각 막대의 길이를 마음대로 줄일 수 있다.

	영선이는 세 막대를 이용해서 아래 조건을 만족하는 삼각형을 만들려고 한다.

	각 막대의 길이는 양의 정수이다
	세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
	삼각형의 둘레를 최대로 해야 한다.
	a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을 작성하시오.

	***
	풀이방법:
	삼각형의 성립 조건 == 세 변의 길이가 주어졌을 때 길이가 가장 긴 변의 길이는 다른 두 변 길이의 합보다 작아야 함
	따라서 가장 큰 변만 구해놓고,
	나머지 두변의 합 + 나머지 두변의 합-1(무조건 가장 큰 변의 길이는 이래야 됨) == 삼각형의 최대 길이
*/


int main(void) {
	int a, b, c;
	int maxLength;
	vector<int> edges;

	cin >> a >> b >> c;

	edges.push_back(a);
	edges.push_back(b);
	edges.push_back(c);

	sort(edges.begin(), edges.end());

	maxLength = edges[0] + edges[1];

	if (maxLength > edges[2]) {
		maxLength += edges[2];
	}
	else {
		maxLength += (maxLength - 1);
	}

	cout << maxLength << '\n';

	return 0;
}