#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;
	int tmp;
	vector<int> tmpVec;
	vector<vector<int>> matrix;
	int tCase;
	int startN, startM, endN, endM;
	int sum = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			tmpVec.push_back(tmp);
		}
		matrix.push_back(tmpVec);
		tmpVec.clear();
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << '\n';
	}*/

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> startN >> startM >> endN >> endM;

		for(int j = startN-1;j < endN;j++){
			for (int k = startM-1; k < endM; k++) {
				sum += matrix[j][k];
			}
		}

		cout << sum << '\n';
		sum = 0;
	}

	return 0;
}