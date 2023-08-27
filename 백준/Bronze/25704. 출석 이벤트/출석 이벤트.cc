#include <iostream>

using namespace std;

/*
	boj25704
	쇼핑몰에서 30일간 출석 이벤트를 진행한다. 
	쇼핑몰의 사이트를 방문하면 1일 1회 출석 도장을 받을 수 있고, 출석 도장을 여러 개 모아서 할인 쿠폰으로 교환할 수 있다.

	출석 도장의 개수에 따라 교환할 수 있는 할인 쿠폰의 종류가 달라진다.

	출석 도장 5개   → 500원 할인 쿠폰
	출석 도장 10개 → 10% 할인 쿠폰
	출석 도장 15개 → 2,000원 할인 쿠폰
	출석 도장 20개 → 25% 할인 쿠폰
	경태가 모은 출석 도장의 개수와 구매할 물건의 가격이 주어졌을 때, 경태가 지불해야 하는 최소 금액을 구하시오. 
	단, 할인 쿠폰은 최대 하나만 적용 가능하다. 할인 금액이 물건의 가격보다 더 큰 경우 지불해야 하는 금액은 0원이다.

	
	도장이 20개 상품이 제일 좋은게 아니고 15개 쿠폰이 더 좋을수도 있음.
	따라서 if-else문이 아니라 if문으로 해서 최소값을 구하는게 포인트.
	그리고 음수일 경우 0원으로 처리
*/

int main(void) {
	int numOfStamp;
	int price;
	int totalPrice=10000000;
	int tmpPrice;

	cin >> numOfStamp >> price;

	totalPrice = price;

	if (numOfStamp >= 5) {
		//cout << "5개 이상\n";
		tmpPrice = price - 500;
		totalPrice = min(tmpPrice, totalPrice);
	}
	if (numOfStamp >= 10) {
		//cout << "10개 이상\n";
		tmpPrice = price * 0.9;
		totalPrice = min(tmpPrice, totalPrice);
	}
	if (numOfStamp >= 15) {
		//cout << "15개 이상\n";
		tmpPrice = price - 2000;
		totalPrice = min(tmpPrice, totalPrice);
	}
	if (numOfStamp >=20 ) {
		//cout << "20개 이상\n";
		tmpPrice = price * 0.75;
		totalPrice = min(tmpPrice, totalPrice);
	}
	
	//음수일경우 0원
	if (totalPrice < 0) {
		totalPrice = 0;
	}

	cout << totalPrice;

	return 0;
}