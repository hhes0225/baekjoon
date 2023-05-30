#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//그리디, 실버3
//피자도우, 토핑 열랑을 더하고 피자 가격으로 나누어서 피자 1판당 최대의 열량을 계산하는 문제
//해결:
//토핑당 열량을 입력받고 sort로 정렬, 그 이후로 reverse로 뒤집기(최대 열량부터 계산하기 위해)
//벡터를 순회하면서 총열량(도우열량+토핑들의 열량)/총가격(도우가격+토핑들의 가격)을 구해서 최대면 갱신, 아니면 break
int main(void) {
	//inputs
	int numOfToping;
	int priceOfDough, priceOfTopings;
	int caloryOfDough;
	int tmp;
	vector<int> caloryOfTopings;

	//outputs
	int maxCalory;
	int maxCaloryPrice;
	int bestPizza;

	cin >> numOfToping >> priceOfDough >> priceOfTopings >> caloryOfDough;

	for (int i = 0; i < numOfToping; i++) {
		cin >> tmp;
		caloryOfTopings.push_back(tmp);
	}

	//열량 큰->작 순으로 정렬
	sort(caloryOfTopings.begin(), caloryOfTopings.end());
	reverse(caloryOfTopings.begin(), caloryOfTopings.end());

	/*cout << "===" << endl;
	for (int i = 0; i < caloryOfTopings.size(); i++) {
		cout << caloryOfTopings[i] << endl;
	}
	cout << "===" << endl;*/


	//초기화: 베스트 피자는 도우/도우가격
	maxCalory = caloryOfDough;
	maxCaloryPrice = priceOfDough;
	bestPizza = maxCalory / maxCaloryPrice;

	for (int i = 0; i < caloryOfTopings.size(); i++) {
		
		tmp = (maxCalory + caloryOfTopings[i]) / (maxCaloryPrice + priceOfTopings);
		maxCalory += caloryOfTopings[i];
		maxCaloryPrice += priceOfTopings;

		/*cout << "this try calory: " << maxCalory + caloryOfTopings[i] << " / this try price : " << maxCaloryPrice + priceOfTopings << endl;
		cout << "this try best pizza?: " << tmp << endl;*/

		if (bestPizza < tmp) {
			
			bestPizza = tmp;
		}
		/*else {
			break;
		}*/
	}

	//bestPizza = maxCalory / maxCaloryPrice;

	//cout << maxCalory << " " << maxCaloryPrice << endl;
	cout << bestPizza << endl;


	return 0;
}