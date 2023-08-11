#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//입력은 여러 개의 테스트 케이스로 이루어져 있다.
//각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 CD의 수 N, 
//선영이가 가지고 있는 CD의 수 M이 주어진다.N과 M은 최대 백만이다.
//다음 줄부터 N개 줄에는 상근이가 가지고 있는 CD의 번호가 오름차순으로 주어진다.
//다음 M개 줄에는 선영이가 가지고 있는 CD의 번호가 오름차순으로 주어진다.
//CD의 번호는 십억을 넘지 않는 양의 정수이다.입력의 마지막 줄에는 0 0이 주어진다.
//
//상근이와 선영이가 같은 CD를 여러장 가지고 있는 경우는 없다.


//첫 시도: find(vector.begin(), vector.end(), 찾을 값)!=vector.end()면 duplicate++ ----> 시간 초과
//두번째 시도: binary_search(vector.begin(), vector.end(), 찾을 값) != true면 duplicate++

int main(void) {
	int n, m;
	int tmp;
	vector<int> nList;
	int duplicate = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			nList.push_back(tmp);
		}

		for (int i = 0; i < m; i++) {
			cin >> tmp;

			if (binary_search(nList.begin(), nList.end(), tmp)) {
				duplicate++;
			}
		}

		cout << duplicate << '\n';
		duplicate = 0;
		nList.clear();
	}

	return 0;
}