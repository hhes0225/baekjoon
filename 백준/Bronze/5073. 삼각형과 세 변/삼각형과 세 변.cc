#include <iostream>
#include <math.h>
//#include <cmath>
using namespace std;

int findMax(int a, int b, int c);

/*
	boj5073

	삼각형의 세 변의 길이가 주어질 때 변의 길이에 따라 다음과 같이 정의한다.

	Equilateral :  세 변의 길이가 모두 같은 경우
	Isosceles : 두 변의 길이만 같은 경우
	Scalene : 세 변의 길이가 모두 다른 경우

	단 주어진 세 변의 길이가 삼각형의 조건을 만족하지 못하는 경우에는 "Invalid" 를 출력한다. 
	예를 들어 6, 3, 2가 이 경우에 해당한다. 
	가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 길지 않으면 삼각형의 조건을 만족하지 못한다.

	세 변의 길이가 주어질 때 위 정의에 따른 결과를 출력하시오.
*/

int main(void) {
	int a, b, c;
	int maxNum;
	int maxIdx;
	bool maxBool = true;
	int spare=0;

	while (1) {
		cin >> a >> b >> c;
		
		// 탈출조건
		if (a == 0 && b == 0 && c == 0)
			break;

		//삼각형의 조건 판단
		//가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 길지 않으면 삼각형의 조건을 만족하지 못한다.
		maxNum = findMax(a, b, c);

		//cout << maxNum << endl;
		
		if (maxNum == a) {
			spare = b + c;
		}
		else if (maxNum == b) {
			spare = a + c;
		}
		else if (maxNum == c) {
			spare = b + a;
		}
		/*else {
			maxBool = false;
			maxIdx = 0;
		}*/

		//cout << maxNum << " " << spare << '\n';

		if (maxNum >= spare) {
			cout << "Invalid" << endl;
			continue;
		}


		//삼각형 성립 완료될 때만 수행
		//삼각형 변의 길이에 따른 분류
		if (a == b && b == c && c==a) {
			cout << "Equilateral" << endl;
		}
		else if (a == b || b == c || c == a) {
			cout << "Isosceles" << endl;
		}
		else if (a!=b && b!=c && c!=a) {
			cout << "Scalene" << endl;
		}
		

	}


	return 0;
}

int findMax(int a, int b, int c) {
	if (a >= b) {
		if (a >= c) {
			return a;
		}
		else {
			return c;
		}
	}
	else if (b >= c) {
		if (b >= a)
			return b;
		else
			return a;
	}
	else if (c >= a) {
		if (c >= b)
			return c;
		return b;
	}
	else
		return 0;
}