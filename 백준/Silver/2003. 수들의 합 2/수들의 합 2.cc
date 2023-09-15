#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int size, goal;
	int tmp;
	vector<int> numList;
	int total = 0;
	int numOfCase = 0;

	cin >> size >> goal;

	for (int i = 0; i < size; i++) {
		cin >> tmp;
		total += tmp;
		numList.push_back(tmp);
	}

	int copyTotal = total;
	int copyTmp;

	for (int i = 0; i < numList.size()+1; i++) {
		if (i != 0) {
			copyTotal -= numList[i - 1];
		}
		
		copyTmp = copyTotal;//이것저것 해보고 다시 돌려놓기 위함 - 백업

		for (int j = numList.size(); j >i; j--) {
			if (j != numList.size()) {
				copyTotal -= numList[j];
			}
			//cout << i << "번째 부터" << j << "번째\n";
			

			//cout << copyTotal << '\n';

			if (copyTotal == goal) {
				//cout << i << "번째 부터" << j << "번째 까지 합\n";
				numOfCase++;
			}
		}

		copyTotal = copyTmp;
	}

	cout << numOfCase << '\n';

	return 0;
}