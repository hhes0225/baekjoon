#include <iostream>
#include <cmath>

using namespace std;


/*
	당신은 어떤 물건이라도 20% 할인해주는 쿠폰을 가지고 있다.

	원래 가격이 주어질 때, 쿠폰을 사용하면 얼마가 되는지 알려주는 프로그램을 작성하시오.

	각 줄에는 물건의 원래가격이 소수점 둘째자리까지 주어진다.

	%.2lf: double형인데 .(소수점) 아래 2자리만
	round: 소수점 아래 몇째자리까지? 안해줌, 1의 자리만 반올림
	따라서 원하는 소수점 자리수만큼의 10의 제곱을 곱해서 1의 자리로 만들어주고
	그다음에 10의 제곱만큼 나눠서 원하는 형태로 롤백
*/

int main(void) {
	int tCase;
	double input;
	double result;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> input;
		
		result = input / 100 * 80;

		result = round(result*1000)/1000;

		printf("$%.2lf\n", result);
	}


	return 0;
}