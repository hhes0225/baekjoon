#include <iostream>
#include <vector>
#define SIZE 9

using namespace std;

/*
	boj 2566
	<그림 1>과 같이 9×9 격자판에 쓰여진 81개의 자연수 또는 0이 주어질 때, 
	이들 중 최댓값을 찾고 그 최댓값이 몇 행 몇 열에 위치한 수인지 구하는 프로그램을 작성하시오.
*/

int main(void) {
	int input;
	vector<int> tmp;
	vector<vector<int>> board;

	//최대값과 최대값이 위치한 행과 열
	int maxValue=0;
	int row, column;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> input;
			tmp.push_back(input);
		}

		board.push_back(tmp);
		tmp.clear();
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (max(maxValue, board[i][j]) == board[i][j]) {
				maxValue = board[i][j];
				row = i;
				column = j;
			}
		}
	}

	cout << maxValue <<'\n';
	cout << row + 1 << " " << column + 1 << '\n';
	//배열 인덱스는 0부터 시작하므로 1 더해서 1부터 시작하는 것으로 바꿔주기
	

	return 0;
}