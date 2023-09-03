#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

/*
	boj2242
	한윤정과 친구들은 이탈리아로 방학 여행을 갔다. 이탈리아는 덥다. 
	윤정이와 친구들은 아이스크림을 사먹기로 했다. 
	
	아이스크림 가게에는 N종류의 아이스크림이 있다. 
	모든 아이스크림은 1부터 N까지 번호가 매겨져있다. 
	어떤 종류의 아이스크림을 함께 먹으면, 맛이 아주 형편없어진다. 
	
	따라서 윤정이는 이러한 경우를 피하면서 아이스크림을 3가지 선택하려고 한다. 
	이때, 선택하는 방법이 몇 가지인지 구하려고 한다.
*/

int main(void) {
	int kindOfIcecream;
	int numOfBannedPair;
	int possibleCombination = 0;
	vector<pair<int, int>> bannedPair;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> kindOfIcecream >> numOfBannedPair;

	//못먹는 쌍 페어를 만들어줌
	for (int i = 0; i < numOfBannedPair; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		//pair도 정렬: e.g. (3, 1)의 경우는 아래 브루트포스 경우에서는 있을 수 없으므로(i=3이면 j=4부터 시작)
		//3, 1 -> 1, 3 으로 정렬한다
		bannedPair.push_back(make_pair(min(tmp1, tmp2), max(tmp1, tmp2)));
	}

	//이진 탐색(binary search)는 정렬된 상태에서만 가능하므로 정렬해준다.
	sort(bannedPair.begin(), bannedPair.end());

	//브루트포스로 3가지 쌍을 만드는 모든 조합을 순회
	for (int i = 1; i <= kindOfIcecream - 2; i++) {
		for (int j = i + 1; j <= kindOfIcecream - 1; j++) {
			//i-j 쌍이 금지조합이라면 k까지 가지말고 탈출
			if (binary_search(bannedPair.begin(), bannedPair.end(), make_pair(i, j))){//!=bannedPair.end()) {//있으면
				continue;
			}

			for (int k = j + 1; k <= kindOfIcecream; k++) {

				//cout << "조합: " << i << ", " << j << ", " << k << endl;
				//j-k 쌍이 금지조합이라면 continue
				if (binary_search(bannedPair.begin(), bannedPair.end(), make_pair(j, k))){// != bannedPair.end()) {
					continue;
				}
				else if (binary_search(bannedPair.begin(), bannedPair.end(), make_pair(i, k))){// != bannedPair.end()) {
					continue;
				}
				else {
					possibleCombination++;
					//cout << "조합: " << i << ", " << j << ", " << k << endl;
				}
			}
		}
	}

	cout << possibleCombination << '\n';


	return 0;
}
