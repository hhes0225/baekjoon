#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void) {
	int tCase = 10;
	int tmp;
	vector<int> inputs;
	vector<int> modulo;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		inputs.push_back(tmp);
	}

	for (int i = 0; i < inputs.size(); i++) {
		
		tmp = inputs[i] % 42;
		//cout << tmp<<" ";

		auto it = find(modulo.begin(), modulo.end(), tmp);

		if (it != modulo.end()) {
			//cout << *(it) << endl;
			continue;
		}
		else{
			//cout << "different" << endl;
			modulo.push_back(tmp);
		}
	}

	cout << modulo.size() << endl;

	return 0;
}