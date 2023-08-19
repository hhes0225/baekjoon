#include <iostream>
#include <vector>

using namespace std;

//미래를 예측하는 능력이 있는 정균이는 앞으로 N일간 ANA 회사의 주가가 어떻게 변하는지 정확히 예측할 수 있다.
//정균이는 예측한 결과를 바탕으로 ANA 회사의 주식 한 주를 적당한 시점에 사고 적당한 시점에 팔아서 최대한의 이득을 얻으려고 한다.
//
//ANA 회사의 앞으로 N일간의 주가를 a_1, a_2, ..., a_N이라고 하자.
//정균이가 i번째 날에 주식을 사고, j번째 날에 판다면,
//a_j - a_i만큼의 이득을 얻을 수 있다.
//
//정균이는 자금이 넉넉하기 때문에 주가가 아무리 높아도 주식을 살 수 있고, 상황이 여의치 않을 경우 사자마자 바로 팔 수도 있다.
//앞으로 N일간 ANA 회사의 주가가 주어졌을 때,
//정균이가 주식 한 주를 적당한 시점에 사고 적당한 시점에 팔아서 얻을 수 있는 최대 이득은 얼마일까 ?

int tabulation(vector<int> stock) {
	int tmpProfit;
	int minBuy;
	int maxProfit=0;

	minBuy = stock[0];

	//stock의 이익(profit) 측정
	//1. 매일 최저치 갱신
	//2. 한 날의 주가가 최저치가 아닐 경우, 이익 계산
	//3. 기존 최대 이익과 비교해서 최대 이익일 경우 갱신
	for (int i = 1; i < stock.size(); i++) {
		minBuy = min(minBuy, stock[i]);
		tmpProfit = stock[i] - minBuy;
		maxProfit = max(maxProfit, tmpProfit);
		//cout << tmpProfit << ' ';
	}


	return maxProfit;
}

int main(void) {
	int tCase;
	int tmp;
	vector<int> stock;
	int maxProfit;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		stock.push_back(tmp);
	}

	maxProfit = tabulation(stock);

	cout << maxProfit << '\n';

	return 0;
}