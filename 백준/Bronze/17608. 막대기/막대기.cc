#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj17608
	아래 그림처럼 높이만 다르고 (같은 높이의 막대기가 있을 수 있음) 모양이 같은 막대기를 일렬로 세운 후, 
	왼쪽부터 차례로 번호를 붙인다. 
	각 막대기의 높이는 그림에서 보인 것처럼 순서대로 6, 9, 7, 6, 4, 6 이다. 
	일렬로 세워진 막대기를 오른쪽에서 보면 보이는 막대기가 있고 보이지 않는 막대기가 있다. 
	즉, 지금 보이는 막대기보다 뒤에 있고 높이가 높은 것이 보이게 된다. 
	예를 들어, 그림과 같은 경우엔 3개(6번, 3번, 2번)의 막대기가 보인다.

	N개의 막대기에 대한 높이 정보가 주어질 때, 오른쪽에서 보아서 몇 개가 보이는지를 알아내는 프로그램을 작성하려고 한다.
*/

int main(void) {
	int tCase;
	vector<int> sticks;
	int maxHeight = 0;
	int show = 0;

	cin >> tCase;
	sticks.resize(tCase);

	for (int i = 0; i < tCase; i++) {
		cin >> sticks[i];
	}

	reverse(sticks.begin(), sticks.end());

	for (int i = 0; i < sticks.size(); i++) {
		if (maxHeight < sticks[i]) {
			maxHeight = sticks[i];
			show++;
		}
	}

	cout << show << '\n';

	return 0;
}