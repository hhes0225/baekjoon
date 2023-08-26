#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
	boj 25912
	알고리즘 입문방 오픈 채팅방에서는 새로운 분들이 입장을 할 때마다 곰곰티콘을 사용해 인사를 한다. 
	이를 본 문자열 킬러 임스는 채팅방의 기록을 수집해 그 중 곰곰티콘이 사용된 횟수를 구해 보기로 했다.

	ENTER는 새로운 사람이 채팅방에 입장했음을 나타낸다. 
	그 외는 채팅을 입력한 유저의 닉네임을 나타낸다. 
	닉네임은 숫자 또는 영문 대소문자로 구성되어 있다.

	새로운 사람이 입장한 이후 처음 채팅을 입력하는 사람은 반드시 곰곰티콘으로 인사를 한다. 
	그 외의 기록은 곰곰티콘을 쓰지 않은 평범한 채팅 기록이다.

	채팅 기록 중 곰곰티콘이 사용된 횟수를 구해보자!

 	★★★★★★★★★
  	unordered_map 하면 시간초과나서 map으로 바꿨더니 해결됨.......
   	찾아보니깐 이미 있는게 확실한 경우 map이 훨씬 빠르다고 함.
    	★★★★★★★★★
*/


int main(void) {
	int tCase;
	string input;
	int gomgom = 0;
	map<string, int> useGomgom;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;

		if (input == "ENTER") {
			useGomgom.clear();
			continue;
		}

		if (useGomgom.find(input) != useGomgom.end()) {//존재하면==이미 인사했으면
			continue;
		}
		else {
			useGomgom.insert(make_pair(input, 1));
			gomgom++;
		}
	}

	cout << gomgom << '\n';

	return 0;
}
