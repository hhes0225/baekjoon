#include<iostream>
#include<unordered_map>
using namespace std;

int main(void) {
	unordered_map<int, int> x;
	unordered_map<int, int> y;
	int tmpx, tmpy;

	for (int i = 0; i < 3; i++) {
		cin >> tmpx >> tmpy;

		if (x.find(tmpx) != x.end()) {//x에 이미 있으면
			x[tmpx]++;
		}
		else {
			x.insert(make_pair(tmpx, 1));
		}

		if (y.find(tmpy) != y.end()) {//y에 이미 있으면
			y[tmpy]++;
		}
		else {
			y.insert(make_pair(tmpy, 1));
		}
	}

	for (auto i = x.begin(); i != x.end(); i++) {
		if (i->second == 1) {
			cout << i->first<<" ";
		}
	}

	for (auto i = y.begin(); i != y.end(); i++) {
		if (i->second == 1) {
			cout << i->first << endl;
		}
	}


	return 0;
}