#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	boj 11652

	준규는 숫자 카드 N장을 가지고 있다. 
	숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 작거나 같다.

	준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오. 
	만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.
*/

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
