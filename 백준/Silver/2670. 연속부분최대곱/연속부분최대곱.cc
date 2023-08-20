#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//N개의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.


double tabulation(vector<double> numbers) {
	double tmp;
	double tmpMax=0;
	double maxValue;
	vector<double> values;

	for (int i = 0; i < numbers.size(); i++) {
		tmp = numbers[i];
		tmpMax = numbers[i];

		//cout << "start: " << tmp << endl;

		if (i == numbers.size() - 1) {
			values.push_back(tmpMax);//마지막 수동반영
			break;
		}

		for (int j = i+1; j < numbers.size(); j++) {
			tmp *= numbers[j];
			//cout << numbers[j] <<"곱한 결과: " << tmp << endl;

			tmpMax = max(tmpMax, tmp);
		}

		values.push_back(tmpMax);
	}

	sort(values.begin(), values.end());

	maxValue = values[values.size() - 1];

	return maxValue;
}

int main(void) {
	int tCase;
	double tmp;
	vector<double> numbers;

	double maxSeqPartMultiply;
	cout.precision(3);

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}


	maxSeqPartMultiply = tabulation(numbers);

	printf("%.3lf\n", round(maxSeqPartMultiply*1000)/1000);

	return 0;
}