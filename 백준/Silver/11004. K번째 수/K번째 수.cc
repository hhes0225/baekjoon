#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj11004
	수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

	둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

	출력
	A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.
*/

int main(void) {
	int n, k;
	vector<int> numbers;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> k;

	numbers.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	cout << numbers[k-1] << endl;

	return 0;
}