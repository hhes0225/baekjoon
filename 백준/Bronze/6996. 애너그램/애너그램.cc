#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int tCase;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		string strA, strB;
		string cpystrA, cpystrB;

		cin >> strA >> strB;

		cpystrA = strA;
		cpystrB = strB;

		sort(strA.begin(), strA.end());
		sort(strB.begin(), strB.end());

		if (strA == strB) {
			cout << cpystrA << " & " << cpystrB << " are anagrams.\n";
		}
		else {
			cout << cpystrA << " & " << cpystrB << " are NOT anagrams.\n";
		}
	}



	return 0;
}