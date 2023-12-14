#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj28431
	양말 $5$개가 주어집니다. 
	각 양말에는 숫자가 하나씩 쓰여있습니다. 
	같은 숫자가 쓰인 양말 두 개를 모으면 양말 한 쌍이 됩니다.

	쌍을 만들 수 있는 양말을 두 개씩 두 쌍 빼면 남는 양말에 쓰인 숫자는 무엇인가요?
*/

int main(void) {
	vector<int> socks;
	int tmp;

	for (int i = 0; i < 5; i++) {
		cin >> tmp;

		if (find(socks.begin(), socks.end(), tmp) != socks.end()) {//존재한다면
			socks.erase(find(socks.begin(), socks.end(), tmp));
		}
		else
			socks.push_back(tmp);

	}

	for (int i = 0; i < socks.size(); i++) {
		cout << socks[i] << endl;
	}



	return 0;
}