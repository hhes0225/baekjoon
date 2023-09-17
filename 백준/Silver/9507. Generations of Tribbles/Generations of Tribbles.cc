#include <iostream>
#include <vector>

using namespace std;

/*
	boj9507
	꿍은 군대에서 진짜 할짓이 없다. 
	그래서 꿍만의 피보나치를 만들어보려고 한다. 
	기존의 피보나치는 너무 단순해서 꿍은 좀더 복잡한 피보나치를 만들어보고자 한다. 
	그래서 다음과 같은 피보나치를 만들었다. 
	
	꿍만의 피보나치 함수가 koong(n)이라고 할 때,
	n < 2 :                         1
	n = 2 :                         2
	n = 3 :                         4
	n > 3 : koong(n − 1) + koong(n − 2) + koong(n − 3) + koong(n − 4)
	이다.

	여러분도 꿍 피보나치를 구해보아라.
*/

vector<unsigned long long int> koongArr;

unsigned long long int koong(int n) {
	unsigned long long int result;

	if (n < 2) {
		koongArr[n] = 1;
		return 1;
	}
	else if (n == 2) {
		koongArr[n] = 2;
		return 2;
	}
	else if (n == 3) {
		koongArr[n] = 4;
		return 4;
	}
	else {
		//정상적으로 값이 들어갔으면 0일리가 없으므로 그럴 경우 적당한 함수 호출
		if (koongArr[n - 4] == 0) {
			koongArr[n - 4] = koong(n - 4);
		}

		if (koongArr[n - 3] == 0) {
			koongArr[n - 3] = koong(n - 3);
		}

		if (koongArr[n - 2] == 0) {
			koongArr[n - 2] = koong(n - 2);
		}

		if (koongArr[n - 1] == 0) {
			koongArr[n - 1] = koong(n - 1);
		}
		
		//만약 값이 있으면 + 없는 경우 위에서 다 dp 테이블 값 채웠으므로
		//dp 테이블에 값이 제대로 들어있는 것이므로 그냥 값을 꺼내온다
		result = koongArr[n - 1] + koongArr[n - 2] + koongArr[n - 3] + koongArr[n - 4];
		koongArr[n] = result;
	}

	/*for (int i = 0; i < koongArr.size(); i++) {
		cout << "koongArr[" << i << "]: " << koongArr[i] << endl;
	}*/

	return result;
}

int main(void) {
	int tCase;
	int input;

	cin >> tCase;

	koongArr = vector<unsigned long long int>(68, 0);//size는 68, 0으로 초기화

	for (int i = 0; i < tCase;  i++) {
		cin >> input;

		unsigned long long int result = koong(input);

		cout << result << '\n';
	}

	return 0;
}