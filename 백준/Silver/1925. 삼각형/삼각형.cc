#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
	boj1925
	평면상에 세 개의 점이 주어지면, 그 세 점으로 이루어지는 삼각형은 유일하게 결정된다. 또는, 삼각형이 이루어지지 않기도 한다. 세 점의 좌표가 주어졌을 때 다음에 따라 이 삼각형의 종류를 판단하는 프로그램을 작성하시오.

	1 세 점이 일직선 위에 있으면 - ‘삼각형이 아님’  출력할 때는 X
	2 세 변의 길이가 같으면 - ‘정삼각형’ 출력할 때는 JungTriangle
	3 두 변의 길이가 같으면
	1 가장 큰 각이 90°보다 크면 - ‘둔각이등변삼각형’ 출력할 때는 Dunkak2Triangle
	2 가장 큰 각이 90°이면 - ‘직각이등변삼각형’ 출력할 때는 Jikkak2Triangle
	3 가장 큰 각이 90°보다 작으면 - ‘예각이등변삼각형’ 출력할 때는 Yeahkak2Triangle
	4 세 변의 길이가 모두 다르면
	1 가장 큰 각이 90°보다 크면 - ‘둔각삼각형’ 출혁할 때는 DunkakTriangle
	2 가장 큰 각이 90°이면 - ‘직각삼각형’ 출력할 때는 JikkakTriangle
	3 가장 큰 각이 90°보다 작으면 - ‘예각삼각형’ 출력할 때는 YeahkakTriangle
*/

/*
	풀이
	1 - 각 점간 기울기 확인 : 일직선 판별
	2 - 각 점간 길이 확인 : 정삼각형 및 이등변삼각형 판별
	3 - 정삼각형 아닐 경우) 삼각형의 각 확인 -> 피타고라스 정리 이용
		a^2 + b^2 = c^2 -> 직각삼각형
		a^2 + b^2 > c^2 -> 예각삼각형
		a^2 + b^2 < c^2 -> 둔각삼각형
*/

vector<pair<int, int>> trianglePoint;
vector<double> triangleSlope;
vector<int> triangleLength;

bool isTriangle() {
	int dxAB = trianglePoint[1].first - trianglePoint[0].first;
	int dyAB = trianglePoint[1].second - trianglePoint[0].second;
	int dxAC = trianglePoint[2].first - trianglePoint[0].first;
	int dyAC = trianglePoint[2].second - trianglePoint[0].second;
	/*
	dyAB / dxAB == dyAC /dxAC 이지만 dxAB 가 0 인 경우도 나올 수 있다.
	따라서  dyAB * dxAC == dyAC * dxAB 형식으로 체크
	*/

	/*cout << dxAB << " " << dyAB << " " << dxAC << " " << dyAC << endl;
	cout << dxAB * dyAC << " " << dyAB * dxAC << endl;
	cout << (dxAB * dyAC == dyAB * dxAC) << endl;*/

	if (dxAB * dyAC == dyAB * dxAC) return false;
	return true;
}

void getLength() {
	triangleLength[0] = pow(trianglePoint[1].first - trianglePoint[0].first, 2) + pow(trianglePoint[1].second - trianglePoint[0].second, 2);
	triangleLength[1] = pow(trianglePoint[2].first - trianglePoint[1].first, 2) + pow(trianglePoint[2].second - trianglePoint[1].second, 2);
	triangleLength[2] = pow(trianglePoint[0].first - trianglePoint[2].first, 2) + pow(trianglePoint[0].second - trianglePoint[2].second, 2);

	//cout << triangleLength[0] << " " << triangleLength[1] << " " << triangleLength[2] << endl;
}

//void getLength() {
//	if (trianglePoint[1].first == trianglePoint[0].first) {
//		triangleLength[0] = pow(trianglePoint[1].second - trianglePoint[0].second, 2);
//	}
//	else if (trianglePoint[1].second == trianglePoint[0].second) {
//		triangleLength[0] = pow(trianglePoint[1].first - trianglePoint[0].first, 2);
//	}
//	else {
//		triangleLength[0] = pow(trianglePoint[1].first - trianglePoint[0].first, 2) + pow(trianglePoint[1].second - trianglePoint[0].second, 2);
//	}
//
//	if (trianglePoint[1].first == trianglePoint[2].first) {
//		//cout << "x좌표가 같음\n";
//		triangleLength[1] = pow(trianglePoint[2].second - trianglePoint[1].second, 2);
//	}
//	else if (trianglePoint[1].second == trianglePoint[2].second) {
//		//cout << "y좌표가 같음\n";
//		triangleLength[1] = pow(trianglePoint[2].first - trianglePoint[1].first, 2);
//	}
//	else {
//		triangleLength[1] = pow(trianglePoint[2].first - trianglePoint[1].first, 2) + pow(trianglePoint[2].second - trianglePoint[1].second, 2);
//	}
//
//	if (trianglePoint[2].first == trianglePoint[0].first) {
//		triangleLength[2] = pow(trianglePoint[2].second - trianglePoint[0].second, 2);
//	}
//	else if (trianglePoint[2].second == trianglePoint[0].second) {
//		triangleLength[2] = pow(trianglePoint[2].first - trianglePoint[0].first, 2);
//	}
//	else {
//		triangleLength[2] = pow(trianglePoint[2].first - trianglePoint[0].first, 2) + pow(trianglePoint[2].second - trianglePoint[0].second, 2);
//	}
//
//	//cout << triangleLength[0] << " " << triangleLength[1] << " " << triangleLength[2] << endl;
//}



int main(void) {
	

	trianglePoint.resize(3);
	triangleSlope.resize(3);
	triangleLength.resize(3);

	//세 점 좌표 입력
	for (int i = 0; i < 3; i++) {
		cin >> trianglePoint[i].first >> trianglePoint[i].second;
	}

	//세 점 기울기 계산
	getLength();
	sort(triangleLength.begin(), triangleLength.end());
	bool isTri = isTriangle();

	//cout << triangleSlope[0] << " " << triangleSlope[1] << " " << triangleSlope[2] << endl;
	if (!isTri) {
		cout << "X\n";
	}
	else {
		//세 점 길이 계산
		

		if (triangleLength[0] == triangleLength[1] && triangleLength[2] == triangleLength[1] && triangleLength[0] == triangleLength[2]) {
			cout << "JungTriangle\n";
		}
		else if (triangleLength[0] == triangleLength[1] || triangleLength[2] == triangleLength[1] ) {
			//이등변삼각형
			if (triangleLength[0] + triangleLength[1] == triangleLength[2]) {
				//직각
				cout << "Jikkak2Triangle\n";
			}
			else if (triangleLength[0] + triangleLength[1] > triangleLength[2]) {
				//예각
				cout << "Yeahkak2Triangle\n";
			}
			else {
				//둔각
				cout << "Dunkak2Triangle\n";
			}
		}
		else {
			//삼각형
			if (triangleLength[0] + triangleLength[1] == triangleLength[2]) {
				//직각
				cout << "JikkakTriangle\n";
			}
			else if (triangleLength[0] + triangleLength[1] > triangleLength[2]) {
				//예각
				cout << "YeahkakTriangle\n";
			}
			else {
				//둔각
				cout << "DunkakTriangle\n";
			}
		}

		
	}


	return 0;
}

//bool isTriangle() {
//	if (trianglePoint[1].first - trianglePoint[0].first == 0){
//		//cout << "분모가 0\n";
//		triangleSlope[0] = INFINITY;
//	}
//	else{
//		triangleSlope[0] = abs((trianglePoint[1].second - trianglePoint[0].second) / static_cast<long double> (trianglePoint[1].first - trianglePoint[0].first));
//	}
//
//	
//	if (trianglePoint[2].first - trianglePoint[1].first == 0){
//		//cout << "분모가 0\n";
//		triangleSlope[1] = INFINITY;
//	}
//	else{
//		triangleSlope[1] = abs((trianglePoint[2].second - trianglePoint[1].second) / static_cast<long double>(trianglePoint[2].first - trianglePoint[1].first));
//	}
//
//
//	if (trianglePoint[0].first - trianglePoint[2].first == 0){
//		//cout << "분모가 0\n";
//		triangleSlope[2] = INFINITY;
//	}
//	else{
//		triangleSlope[2] = abs((trianglePoint[0].second - trianglePoint[2].second) / static_cast<long double>(trianglePoint[0].first - trianglePoint[2].first));
//	}
//
//	if ((triangleSlope[0] == triangleSlope[1]) && (triangleSlope[1] == triangleSlope[2]) && (triangleSlope[2] == triangleSlope[0]))
//		return false;
//	else
//		return true;
//}