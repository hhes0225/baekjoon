#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	int setA, setB;
	int tmp;
	unordered_map<int, int> sets;
	int result = 0;

	cin >> setA >> setB;

	for (int i = 0; i < setA; i++) {
		cin >> tmp;
		if (sets.find(tmp) != sets.end()) {//맵에 있으면 수량? + 1
			sets[tmp]++;

		}
		else {//없으면 새로 추가
			sets.insert(make_pair(tmp, 1));
		}
	}

	for (int i = 0; i < setB; i++) {
		cin >> tmp;
		if (sets.find(tmp) != sets.end()) {//맵에 있으면 수량? + 1
			sets[tmp]++;

		}
		else {//없으면 새로 추가
			sets.insert(make_pair(tmp, 1));
		}
	}

	for (auto it = sets.begin(); it != sets.end(); it++) {
		if (it->second < 2) {
			result++;
		}
	}

	cout << result << endl;

	return 0;
}