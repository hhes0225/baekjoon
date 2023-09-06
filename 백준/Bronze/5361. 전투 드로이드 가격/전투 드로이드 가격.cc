#include <iostream>

using namespace std;

/*
	상근이는 망가진 전투 드로이드를 고치려고 하고 있다. 전투 드로이드의 각 부품의 가격은 다음과 같다.

	블래스터 라이플	\$350.34
	시각 센서	\$230.90
	청각 센서	\$190.55
	팔	\$125.30
	다리	\$180.90
	입력
	첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 음이 아닌 정수 다섯 개(A B C D E)로 이루어져 있다.
	
	A: 필요한 블래스터 라이플의 개수
	B: 필요한 시각 센서의 개수
	C: 필요한 청각 센서의 개수
	D: 필요한 팔의 수
	E: 필요한 다리의 수
 
	출력
	각 테스트 케이스 마다, 입력으로 주어진 부품을 모두 구매하는데 필요한 비용을 소수점 둘째 자리까지 출력한다. 달러 표시도 출력해야 한다. 정답은 1억보다 작거나 같다.
*/

int main(void) {
	int tCase;
	int aBlasterRiffle, bVisualSensor, cAuditorySensor, dArm, eLeg;
	double totalPrice=0;
	double aPrice = 350.34, bPrice = 230.90, cPrice = 190.55, dPrice = 125.30, ePrice = 180.90;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> aBlasterRiffle >> bVisualSensor >> cAuditorySensor >> dArm >> eLeg;

		//수량 * 가격의 총합
		totalPrice += aBlasterRiffle * aPrice;
		totalPrice += bVisualSensor * bPrice;
		totalPrice += cAuditorySensor * cPrice;
		totalPrice += dArm * dPrice;
		totalPrice += eLeg * ePrice;

		printf("$%.2lf\n", totalPrice);
		totalPrice = 0;//다음 반복을 위해 초기화
	}

	return 0;
}
