#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	boj 1065
	어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
	등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
	N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

int howManyHansu(int input) {
	int hansu = 0;

	//범위: 1부터 input까지
	for (int i = 1; i <= input; i++) {
		if (i < 100)
			hansu++;

		else {
			string hansuStr = to_string(i);
			vector<int> diff;
			bool isHansu=true;

			for (int j = 1; j < hansuStr.size(); j++) {
				diff.push_back(((int)hansuStr[j - 1] - (int)'0') - ((int)hansuStr[j] - (int)'0'));
			}

			for (int j = 1; j < diff.size(); j++) {
				
				if (diff[j - 1] == diff[j]) {
					continue;
				}
				else{
					isHansu = false;
				}
			}

			if (isHansu)
				hansu++;
		}
	}

	return hansu;
}

int main(void) {
	int input;
	int hansu;

	cin >> input;
	hansu = howManyHansu(input);

	cout << hansu << endl;

	return 0;
}