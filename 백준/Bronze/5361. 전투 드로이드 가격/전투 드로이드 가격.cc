#include <iostream>

using namespace std;

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