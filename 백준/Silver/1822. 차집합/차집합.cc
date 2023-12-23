#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	boj1822
	몇 개의 자연수로 이루어진 두 집합 A와 B가 있다. 
	집합 A에는 속하면서 집합 B에는 속하지 않는 모든 원소를 구하는 프로그램을 작성하시오.
*/

int main(void) {
	int aSize, bSize;
	vector<int> a, b;

	cin >> aSize >> bSize;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	a.resize(aSize);
	b.resize(bSize);

	for (int i = 0; i < aSize; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < bSize; i++) {
		cin >> b[i];
	}
	

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> result;


	int i = 0;
	while (1) {
		if (i == a.size()) {
			break;
		}

		if (!binary_search(b.begin(), b.end(), a[i])) {
			result.push_back(a[i]);
		}

		i++;

	}

	if (result.empty()) {
		cout << "0\n";
	}
	else {
		cout << result.size()<<"\n";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
	}
	



	return 0;
}