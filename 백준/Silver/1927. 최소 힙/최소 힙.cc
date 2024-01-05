#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	priority_queue<int, vector<int>, greater<int>> pq;
	//priority queue는 내림차순이므로 오름차순으로 바꿔준다.
	int tCase;
	int input;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		if (input == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}

	return 0;
}