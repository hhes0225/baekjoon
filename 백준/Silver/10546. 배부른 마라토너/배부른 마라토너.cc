#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
	boj10546
	마라토너라면 국적과 나이를 불문하고 누구나 참가하고 싶어하는 백준 마라톤 대회가 열린다. 
	42.195km를 달리는 이 마라톤은 모두가 참가하고 싶어했던 만큼 매년 모두가 완주해왔다. 단, 한 명만 빼고!

	모두가 참가하고 싶어서 안달인데 이런 백준 마라톤 대회에 참가해 놓고 완주하지 못한 배부른 참가자 한 명은 누굴까?
*/

int main(void) {
	int pplNum;
	unordered_map<string, int> participants;

	cin >> pplNum;

	

	for (int i = 0; i < pplNum; i++) {
		string name;
		cin >> name;

		if (participants.find(name) != participants.end()) {
			participants[name]++;
			continue;
		}

		participants.insert({ name, 1 });
	}


	for (int i = 0; i < pplNum - 1; i++) {
		string name;
		cin >> name;

		participants[name]++;
	}

	for (auto i = participants.begin(); i != participants.end(); i++) {
		if ((i->second) % 2 == 0) {
			continue;
		}
		else {
			cout << (i->first) << '\n';
			break;
		}
	}


	return 0;
}