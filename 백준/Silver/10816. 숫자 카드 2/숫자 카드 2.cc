#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main(void) {
	int tCase;
	int tmp;
	unordered_map<int, int> cards;
	vector<int> order;

	cin >> tCase;

	//상근이가 가지고 있는 카드들과 그 개수 삽입
	for (int i = 0; i < tCase; i++) {
		cin >> tmp;

		if (i == 0){
			cards.insert(make_pair(tmp, 1));
			continue;
		}

		//mapName.find(찾을 값) != mapName.end() ->true면 존재한다는 의미
		if (cards.find(tmp) != cards.end()) {
			cards[tmp]++;
		}
		else {
			cards.insert(make_pair(tmp, 1));
		}

	}

	/*cout << "===" << endl;
	for (auto i = cards.begin(); i != cards.end(); i++) {
		cout << i->first << ": " << i->second << endl;
	}
	cout << "===" << endl;*/

	//상근이가 몇 개 가지고 있는 숫자 카드인지 판단하기 위한 input 카드들
	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		order.push_back(tmp);
	}

	for (int i = 0; i < order.size(); i++) {

		//input 카드가 상근이가 가지고 있는 카드라면 상근 소유 카드 개수 출력
		if (cards.find(order[i]) != cards.end()) {
			cout << cards[order[i]] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
	
	return 0;
}