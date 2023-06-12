#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	int sCardCase;
	int tmp;
	int inCardCase;
	unordered_map <int, int> sCard;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> sCardCase;

	for (int i = 0; i < sCardCase; i++) {
		cin >> tmp;
		if (sCard.find(tmp) != sCard.end()) {//맵에 존재하면
			sCard[tmp]++;
		}
		else {//존재하지 않으면 신규추가
			sCard.insert(make_pair(tmp, 1));
		}
	}

	cin >> inCardCase;

	for (int i = 0; i < inCardCase; i++) {
		cin >> tmp;

		if (sCard.find(tmp) != sCard.end()) {//맵에 존재하면
			cout << sCard[tmp] << ' ';
		}
		else {//존재하지 않으면 0 출력
			cout << 0 << ' ';
		}
	}

	cout << '\n';

	return 0;
}