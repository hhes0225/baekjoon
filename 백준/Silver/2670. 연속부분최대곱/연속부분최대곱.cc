#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//N개의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.


double bruteForce(vector<double> numbers) {
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

double dp_bottomUp(vector<double> arr){
	vector<double> dp;//dp table
	double tmpValue;
	double maxSeqMulValue=0;

	dp.push_back(0);//일단 하나 만들기

	//dp table의 초기값 설정: arr의 첫번째값 단일값
	//0.5 0.4 0.3 0.2 0.1의 경우 최대값은 0.5
	dp[0] = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		tmpValue = max(arr[i], dp[i - 1] * arr[i]);
		//input 배열 자기 자신, dp table에 저장한 과거 값과 자기 자신 곱한 값 비교
		//그렇게 되면 자기 자신일 때 -> 다시 자기 자신부터 시작, 이후 누적
		// dp table에 저장한 과거값 * 자기 자신이 클 때 -> 과거 값에 누적곱

		dp.push_back(tmpValue);
		maxSeqMulValue = max(maxSeqMulValue, tmpValue);
	}

	//dp table은 연산에 사용될 뿐, 최종적으로 나오는 값은 따로 있음

	return maxSeqMulValue;
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


	maxSeqPartMultiply = dp_bottomUp(numbers);

	printf("%.3lf\n", round(maxSeqPartMultiply*1000)/1000);

	return 0;
}