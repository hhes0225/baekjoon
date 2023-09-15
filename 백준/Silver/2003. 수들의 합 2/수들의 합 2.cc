#include <iostream>
#include <vector>

using namespace std;

/*
	boj2003
	N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 
	이 수열의 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

	부분합->하나하나 더하는것보다 다 더한거에서 하나씩 빼는게 더 나은듯
*/

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
