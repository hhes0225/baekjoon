#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	int tCase;
	long long int tmp;
	map<long long int, int> ownCard;
	int maxAmount=0;
	long long int maxCardNum;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;

		if (ownCard.find(tmp) != ownCard.end()) {//이미 카드를 가지고 있으면
			ownCard[tmp]++;
		}
		else {//해당 카드를 처음 가지고 있는 것이라면
			ownCard.insert(make_pair(tmp, 1));
		}
	}

	for (auto it = ownCard.begin(); it != ownCard.end(); it++) {
		if (it->second > maxAmount) {
			maxCardNum = it->first;
			maxAmount = it->second;
		}
	}

	cout << maxCardNum << '\n';

	return 0;
}