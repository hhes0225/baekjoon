#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	boj 1100

	체스판은 8×8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다. 
	가장 왼쪽 위칸 (0,0)은 하얀색이다. 
	체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지 출력하는 프로그램을 작성하시오.

*/

int main(void) {
	string input;
	vector<string> chessboard;
	int chesspiece = 0;

	for (int i = 0; i < 8; i++) {
		cin >> input;

		chessboard.push_back(input);
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (i % 2 == 1) {//홀수 행
				if (j % 2 == 1) {//홀수 열
					//이 영역은 흰색 영역
					if (chessboard[i - 1][j - 1] == 'F') {
						chesspiece++;
					}
				}
				else {//짝수 열
					//이 영역은 검정색 영역
					continue;
				}
			}
			else {//짝수 행
				if (j % 2 == 1) {//홀수 열
					//이 영역은 검정색 영역
					continue;
				}
				else {//짝수 열
					//이 영역은 흰색 영역
					if (chessboard[i - 1][j - 1] == 'F') {
						chesspiece++;
					}
				}

			}
		}
	}

	cout << chesspiece << '\n';

	return 0;
}