#include <iostream>
#include <vector>

using namespace std;

/*
	boj 2775
	평소 반상회에 참석하는 것을 좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.

	이 아파트에 거주를 하려면 조건이 있는데, 
	“a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다” 
	는 계약 조항을 꼭 지키고 들어와야 한다.

	아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때, 
	주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라. 
	단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.

	상태를 통해서 배열을 표현!!
	
	apartment[층수][호수 상태]
*/

vector<vector<int>> apartment;

void tabulation(int floor, int door) {
	apartment.resize(floor+1);//0층부터 시작

	for (int i = 0; i < floor+1; i++) {//0호가 아니라 1호부터 나오기 때문에 사이즈 설정+1
		//cout << "방만들기\n";
		apartment[i] = vector<int>(door + 2, 0);
	}

	//0층 층설정(초기설정)
	for (int i = 1; i <= door; i++) {
		//cout << "0층 초기화\n";
		apartment[0][i] = i;
	}
	//cout << "초기화 완\n";
	//다른층 dp로 채워나가기

	//for (int i = 0; i < apartment.size(); i++) {//층수: 0층은 초기설정으로 채웠으니까 제외
	//	for (int j = 1; j <= door; j++) {//호수: 호수는 1호부터 시작
	//		cout << apartment[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	for (int i = 1; i < apartment.size(); i++) {//층수: 0층은 초기설정으로 채웠으니까 제외
		//cout << "dp 층수 loop 진입\n";


		for (int j = 1; j <=door;  j++) {//호수: 호수는 1호부터 시작
			//cout << "dp 호수 loop 진입\n";
			if (j == 1) {
				//cout << "1호 케이스 처리\n";
				apartment[i][j] = apartment[i - 1][j];
				continue;
			}

			if (apartment[i][j] == 0) {//값이 없으면
				//cout << "다른 호 사람들 \n";
				apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
			}


		}
	}

	//for (int i = 0; i < apartment.size(); i++) {//층수: 0층은 초기설정으로 채웠으니까 제외
	//	for (int j = 1; j <= door; j++) {//호수: 호수는 1호부터 시작
	//		cout << apartment[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	return;
}

int main(void) {
	int tCase;
	int inFloor, inDoor;

	cin >> tCase; 

	for (int i = 0; i < tCase; i++) {
		cin >> inFloor >> inDoor;

		tabulation(inFloor, inDoor);

		cout << apartment[inFloor][inDoor] << "\n";
	}

	return 0;
}