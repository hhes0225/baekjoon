#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	boj26068
	마음씨 착한 곰곰이는 임스에게 치킨 기프티콘을 여러 번 선물했다.

	기프티콘이 있다는 사실을 잊고 있던 임스는 치킨 댄스를 추는 곰곰이를 보고 그 사실이 생각났다.

	치킨 기프티콘을 선물받은 횟수
	N과 선물의 남은 유효기간이 주어질 때, 임스가 사용할 기프티콘의 개수를 구하시오.

	임스는 기프티콘을 아껴 사용하기 위해 유효기간이 90일 이하로 남은 기프티콘만 사용할 것이다.
*/

int main(void) {
	int tCase;
	string input;
	vector<int> maybeUse;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		input.erase(input.begin());
		input.erase(input.begin());

		if (stoi(input) <= 90) {
			maybeUse.push_back(stoi(input));
		}
	}

	cout << maybeUse.size() << endl;

	return 0;
}