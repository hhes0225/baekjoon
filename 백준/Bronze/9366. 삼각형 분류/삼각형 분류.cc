#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int tCase;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int input;
		vector<int> edges;

		for (int j = 0; j < 3; j++) {
			cin >> input;
			edges.push_back(input);
		}

		sort(edges.begin(), edges.end());

		cout << "Case #" << i + 1 << ": ";

		if (edges[0] + edges[1] <= edges[2]) {
			cout << "invalid!" << '\n';
		}
		else if (edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[0]) {
			cout << "equilateral" << '\n';
		}
		else if (edges[0] == edges[1] || edges[1] == edges[2] || edges[2] == edges[0]) {
			cout << "isosceles" << '\n';
		}
		else {
			cout << "scalene" << '\n';
		}

	}

	return 0;
}