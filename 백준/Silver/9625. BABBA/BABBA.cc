#include <iostream>
using namespace std;

//상근이는 길을 걷다가 신기한 기계를 발견했다.
//기계는 매우 매우 큰 화면과 버튼 하나로 이루어져 있다.
//기계를 발견했을 때, 화면에는 A만 표시되어져 있었다.
//버튼을 누르니 글자가 B로 변했다.
//한 번 더 누르니 BA로 바뀌고, 그 다음에는 BAB, 그리고 BABBA로 바뀌었다.
//상근이는 화면의 모든 B는 BA로 바뀌고, A는 B로 바뀐다는 사실을 알게되었다.
//버튼을 K번 눌렀을 때, 화면에 A와 B의 개수는 몇 개가 될까 ?


/*
	DP(Dynamic programming)
	: 이미 한번 계산했다면 , 메모장에 적어놓고 나중에 또 계산하지 말고 가져다 쓰자!

	DP를 구현하기 위한 2가지 방법
	1. Memoization : 재귀함수로 DP 구현
	2. Tabulation : 반복문으로 DP 구현

	구현방법
	1. 점화식 구하기(f(n))
	2. 초기 base case 구하기 (f(0), f(1) 등...)
*/



pair<int, int> tabulationDP(int n) {
	int tableA[45] = { 0, };
	int tableB[45] = { 0, };

	tableA[0] = 1;
	tableA[1] = 0;
	
	tableB[0] = 0;
	tableB[1] = 1;

	for (int i = 2; i <= n; i++) {
		tableA[i] = tableB[i - 1];
		tableB[i] = tableA[i - 1] + tableB[i - 1];
	}

	pair<int, int> result = make_pair(tableA[n], tableB[n]);

	return result;
}

int main(void) {
	int n;
	pair<int, int> result;

	cin >> n;

	result = tabulationDP(n);

	cout << result.first << " " << result.second << "\n";

	return 0;
}