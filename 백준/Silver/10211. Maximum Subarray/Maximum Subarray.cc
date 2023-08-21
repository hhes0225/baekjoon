#include <iostream>
#include <vector>

using namespace std;

//백준 10211
//크기 N인 정수형 배열 X가 있을 때, 
//X의 부분 배열(X의 연속한 일부분) 중 각 원소의 합이 가장 큰 부분 배열을 찾는 
//Maximum subarray problem(최대 부분배열 문제)은 컴퓨터 과학에서 매우 잘 알려져 있다.
//
//여러분은 N과 배열 X가 주어졌을 때, X의 maximum subarray의 합을 구하자.즉, max1 ≤ i ≤  j ≤ N(X[i] + ... + X[j])를 구하자.

//참고: 2670 연속 최대 부분 누적곱

//***************** 주어진 수가 음수일수도 있음!!! 이 경우를 고려해서 dp 테이블과 maxValue를 초기화해야 함

int dp_bottomUp(vector<int> arr) {
	vector<int> dp;
	//계산에만 활용될 dp 테이블
	int tmpValue;//이걸 dp 테이블에 push_back 할 예정
	int maxValue=-10000; //dp에서 추출한 최대값

	dp.push_back(-1000);

	//dp 테이블의 초기값 설정
	//5 -1 -1 -1 -1의 경우 첫 번째 값이 5가 최대값이 되기 때문
	dp[0] = arr[0];

	//초기값 제외하고(idx 0) idx 1부터 시작
	for (int i = 1; i < arr.size(); i++) {
		tmpValue = max(arr[i], dp[i - 1] + arr[i]);
		//input: 현재 단일값, 과거값+현재값의 누적합
		//현재 단일값이 더 클 경우: 현재 단일값 dp 테이블 저장 & 현재 단일값부터 다시 누적합 구하기 시작
		//과거값+현재값이 더 클 경우: 과거 합+현재값 누적합을 dp 테이블에 저장

		dp.push_back(tmpValue);

		//dp 테이블에서 최대값을 추출
		maxValue = max(maxValue, dp[i]);
	}

	if (dp.size() == 1) {
		maxValue = dp[0];
	}

	return maxValue;
}

int main(void) {
	int tCase;
	int numOfarray;
	int tmp;
	vector<int> arr;
	int sumOfMaxSubarr;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> numOfarray;

		for (int j = 0; j < numOfarray; j++) {
			cin >> tmp;
			arr.push_back(tmp);
		}

		sumOfMaxSubarr = dp_bottomUp(arr);
		
		printf("%d\n", sumOfMaxSubarr);

		arr.clear();
	}
}