#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	int memoCase, tCase;
	unordered_map<string, string> memos;
	string tmpSite, tmpPw;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> memoCase >> tCase;

	for (int i = 0; i < memoCase; i++) {
		cin >> tmpSite >> tmpPw;
		memos.insert(make_pair(tmpSite, tmpPw));
	}

	for (int i = 0; i < tCase; i++) {
		cin >> tmpSite;

		if (memos.find(tmpSite) != memos.end()) {
			cout << memos[tmpSite] << '\n';
		}
	}

	return 0;
}