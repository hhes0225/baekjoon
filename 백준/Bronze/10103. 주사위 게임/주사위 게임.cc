#include<iostream>

using namespace std;

int main(void) {
	int changtotal = 100, sangtotal=100;
	int tCase;
	int changTmp, sangTmp;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> changTmp >> sangTmp;

		if (changTmp < sangTmp)
			changtotal -= sangTmp;
		else if (changTmp > sangTmp)
			sangtotal -= changTmp;
		else
			continue;
	}

	cout << changtotal << endl << sangtotal << endl;


	return 0;
}