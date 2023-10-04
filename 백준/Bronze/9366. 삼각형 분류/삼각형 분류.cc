#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	꿍은 오늘 학교에서 삼각형에 대해 배웠다. 삼각형은 변의 길이에 따라 다음과 같이 분류될 수 있다.

	정삼각형(equilateral triangle)은 모든 변의 길이가 같다. 각 역시 60도로 모두 같다.
	이등변삼각형(isosceles triangle)은 두 개의 변의 길이가 같다. 각 역시 두 개의 각의 크기가 같다.
	부등변삼각형(scalene triangle)은 모든 변의 길이가 같지 않다. 각 역시 모두 다르다. 몇몇 부등변삼각형의 경우 직각삼각형이다.
	수학선생님이 삼각형의 세 변의 길이를 가지고 삼각형을 분류하라는 숙제를 내줬는데 꿍은 정말 놀고싶다. 꿍이 놀수있도록 여러분이 도와주어라.
*/

int main(void) {
	int tCase;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int input;
		vector<int> edges;

		for (int j = 0; j < 3; j++) {
			cin >> input;
			edges.push_back(input);
		}

		sort(edges.begin(), edges.end());

		cout << "Case #" << i + 1 << ": ";

		if (edges[0] + edges[1] <= edges[2]) {
			cout << "invalid!" << '\n';
		}
		else if (edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[0]) {
			cout << "equilateral" << '\n';
		}
		else if (edges[0] == edges[1] || edges[1] == edges[2] || edges[2] == edges[0]) {
			cout << "isosceles" << '\n';
		}
		else {
			cout << "scalene" << '\n';
		}

	}

	return 0;
}
