#include <iostream>
#include <cmath>

using namespace std;

/*
	boj10984
	게으른 근우는 열심히 놀다가 문득, 자신의 학점 평균이 얼마일지 궁금해졌다. 
	학사시스템도 들어가기 귀찮아하는 근우를 위해 구해주도록 하자.
*/

int main(void) {
	int tCase;
	int subjects;
	int credit;

	double grade;
	double avg;

	cin >> tCase;
	
	for (int i = 0; i < tCase; i++) {
		int creditSum = 0;	
		double sum = 0.0;
		cin >> subjects;

		for (int j = 0; j < subjects; j++) {
			cin >> credit >> grade;
			
			creditSum += credit;
			sum += grade*credit;
		}

		avg = sum / (double)creditSum;

		printf("%d %.1lf\n", creditSum, avg);
	}


	return 0;
}