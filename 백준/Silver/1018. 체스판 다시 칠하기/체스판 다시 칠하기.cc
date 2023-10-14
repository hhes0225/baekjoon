#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
	boj1018
	지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 
	어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 
	지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

	체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 
	구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
	따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 
	
	하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

	보드가 체스판처럼 칠해져 있다는 보장이 없어서, 
	지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 
	당연히 8*8 크기는 아무데서나 골라도 된다. 
	지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

*/

/*
	브루트포스 
	-> 왼쪽 위가 흰색인 경우
	-> 왼쪽 위가 검은색인 경우

	두개를 구하고 최소값을 저장

	**** POINT!!!!! ****
	전체 보드에서 고쳐야 될 수를 찾는 게 아니라,
	전체 보드에서 일부인 8x8칸만 선택해서
	그 해당 칸 내부에서만 고칠 수를 찾으면 됨!!
	즉, 10x10 보드일 경우 거기서 8x8 만 선택하면 됨
*/

int whiteFirstCase(int rowStartPoint, int colStartPoint, vector<string> board) {
	int change = 0;

	for (int i = rowStartPoint; i < rowStartPoint + 8; i++) {
		for (int j = colStartPoint; j < colStartPoint + 8; j++) {

			//cout << "i, j: " << i << ", " << j<<"\t";
			if ((i + 1) % 2 == 1) {//홀수 라인
				if ((j + 1) % 2 == 1) {//홀수 칸: 화이트여야 함
					if (board[i][j] != 'W') {
						//cout << i << ", " << j << ": 홀홀 화이트" << '\n';
						change++;
					}
				}
				else {//짝수 칸: 블랙이어야 함
					if (board[i][j] != 'B') {
						//cout << i << ", " << j << "홀짝 블랙" << '\n';
						change++;
					}
				}
			}
			else {//짝수 라인
				if ((j + 1) % 2 == 1) {//홀수 칸: 블랙이어야 함
					if (board[i][j] != 'B') {
						//cout << i << ", " << j << "짝홀 블랙" << '\n';
						change++;
					}
				}
				else {//짝수 칸: 화이트여야 함
					if (board[i][j] != 'W') {
						//cout << i << ", " << j << "짝짝 화이트" << '\n';
						change++;
					}
				}
			}
		}
		//cout << '\n';
	}

	return change;
}

int blackFirstCase(int rowStartPoint, int colStartPoint, vector<string> board) {
	int change = 0;

	for (int i = rowStartPoint; i < rowStartPoint+8; i++) {
		for (int j = colStartPoint; j < colStartPoint+8; j++) {
			if ((i + 1) % 2 == 1) {//홀수 라인
				if ((j + 1) % 2 == 1) {//홀수 칸: 블랙이어야 함
					if (board[i][j] != 'B') {
						change++;
					}
				}
				else {//짝수 칸: 화이트여야 함
					if (board[i][j] != 'W') {
						change++;
					}
				}
			}
			else {//짝수 라인
				if ((j + 1) % 2 == 1) {//홀수 칸: 화이트여야 함
					if (board[i][j] != 'W') {
						change++;
					}
				}
				else {//짝수 칸: 블랙이어야 함
					if (board[i][j] != 'B') {
						change++;
					}
				}
			}
		}
	}

	return change;
}

int main(void) {
	int row, col;
	string inputRow;
	vector<string> chessBoard;
	int whiteFirst=999999;
	int blackFirst=999999;
	int minChange;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		cin >> inputRow;

		chessBoard.push_back(inputRow);
	}

	for (int i = 0; i <= row - 8; i++) {
		//cout << "case i: " << i << "\n";
		for (int j = 0; j <= col - 8; j++) {
			//cout << "case j: " << j << "\n";
			whiteFirst = min(whiteFirst, whiteFirstCase(i, j, chessBoard));
			blackFirst = min(blackFirst, blackFirstCase(i, j, chessBoard));
		}
	}
	
	//cout << whiteFirst << " " << blackFirst << '\n';

	minChange = min(whiteFirst, blackFirst);

	cout << minChange << '\n';


	return 0;
}

//int main(void) {
//	/*
//		체커보드에서 8x8 사이즈만 가져와서 잘못 칠해진 부분 최소한으로 고치기
//		1. 스트링을 받는다(스트링도 배열처럼 인덱스로 접근 가능
//		2. 열만큼 순회하면서 8x8 보드를 순회한다(이중포문으로 8x8만
//		3. 8x8 안되면 이중포문 빠져나오기
//		4. 삼중포문 해서 피벗 따져야겠는데?
//	*/
//	int row;
//	int col;
//	string input;
//	vector <string> checkerboard;
//	int tmpChange = 0;
//	int minChange = 0;
//
//	cin >> row >> col;
//
//	for (int i = 0; i < row; i++) {
//		cin >> input;
//		checkerboard.push_back(input);
//	}
//
//	for (int i = 0; i < row; i++) {
//		cout << checkerboard[i];
//		cout << endl;
//	}
//	
//	int pivoti = 0, pivotj = 0;
//
//	while (1) {
//		if (pivoti == row - 1 && pivotj == col - 1)
//			break;
//
//		else if (pivoti + 8 > row || pivotj + 8 > col)
//			continue;
//
//		for (int i = pivoti; i < pivoti; i++) {
//			for (int j = pivotj; j < pivotj; j++) {
//				
//			}
//		}
//
//		if (tmpChange < minChange) {
//			minChange = tmpChange;
//			tmpChange = 0;
//		}
//
//	}
//
//	return 0;
//}