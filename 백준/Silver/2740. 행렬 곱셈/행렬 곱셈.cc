#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m, k;
	vector<vector<int>> matrixA, matrixB, newMatrix;
	int tmp;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> tmpVec;
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			tmpVec.push_back(tmp);
		}
		matrixA.push_back(tmpVec);
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrixA[i][j]<<" ";
		}
		cout << '\n';
	}*/

	cin >> m >> k;

	for (int i = 0; i < m; i++) {
		vector<int> tmpVec;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			tmpVec.push_back(tmp);
		}
		matrixB.push_back(tmpVec);
	}

	for (int i = 0; i < n; i++) {
		vector<int> tmpVec;

		for (int j = 0; j < k; j++) {
			int sum=0;
			for (int l = 0; l < m; l++) {
				sum += (matrixA[i][l] * matrixB[l][j]);
			}

			tmpVec.push_back(sum);
		}

		newMatrix.push_back(tmpVec);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << newMatrix[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}