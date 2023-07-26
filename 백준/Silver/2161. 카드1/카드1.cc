#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int numOfCard;
	deque<int> cards;
	int tmp;

	cin >> numOfCard;

	for (int i = 1; i <= numOfCard; i++) {
		cards.push_back(i);
	}

	while (1) {
		if (cards.size() == 0) {
			break;
		}

		cout << cards[0] << ' ';
		cards.pop_front();

		if (cards.size() == 0) {
			break;
		}
		else{
			tmp = cards[0];
			cards.pop_front();

			cards.push_back(tmp);
		}
	}

	cout << '\n';

	return 0;
}