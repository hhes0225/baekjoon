#include<iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	int input;
	map<int, int> needSet;
	bool isSix = false;
	bool isNine = false;
	int maxSet=0;

	for (int i = 0; i < 9; i++) {
		needSet.insert(make_pair(i, 0));
	}

	cin >> input;

	for (int i = 0; i < to_string(input).size(); i++) {
		if(to_string(input)[i]=='6'|| to_string(input)[i] == '9'){
			if (isSix == false && isNine == true) {
				//cout << "6 증가1" << endl;
				needSet[6]++;
				isNine = false;
				continue;
			}
			else if (isSix == true && isNine == false) {
				//cout << "6 증가2" << endl;
				needSet[6]++;
				isSix = false;
				continue;
			}
			else {
				//cout << "6 안증가2" << endl;
				isNine = true;
				continue;
			}
		}
		else {
			needSet[to_string(input)[i] - '0']++;
		}
	}

	if (isNine || isSix) {
		needSet[6]++;
	}

	for (auto it = needSet.begin(); it != needSet.end(); it++) {
		maxSet = max(maxSet, it->second);
	}

	cout << maxSet << '\n';

	return 0;
}

//int main(void) {
//	string input;
//	string inputCopy;
//	char check;
//	bool sixAndNineExist = false;
//	bool sixAndNine = false;
//	int numOfSet = 0;
//
//	cin >> input;
//
//	for (int i = 0; i < input.size(); i++) {
//		inputCopy = input;
//		check = inputCopy[i];
//		//inputCopy.erase(i);
//		inputCopy[i] = 'a';
//
//		//cout << "check: " << check << ", inputCopy" << inputCopy << endl;
//
//		if (inputCopy.find(check) != string::npos) {//있으면
//			if (check == '6') {
//				sixAndNineExist = true;
//				//cout << 6 << endl;
//				if (sixAndNine) {//있으면
//					//cout << "69 이미 품절" << endl;
//					numOfSet++;
//					sixAndNine = false;
//				}
//				else {
//					//cout << "69아직 안품절" << endl;
//					sixAndNine = true;
//				}
//			}
//			else if (check=='9') {
//				sixAndNineExist = true;
//				//cout << 9 << endl;
//				if (sixAndNine) {//있으면
//					//cout << "96 이미 품절" << endl;
//					numOfSet++;
//					sixAndNine = false;
//				}
//				else {
//					//cout << "96아직 안품절" << endl;
//					sixAndNine = true;
//				}
//			}
//			else {
//				//cout << "아무것도" << endl;
//				numOfSet++;
//			}
//			continue;
//		}
//	}
//
//	if (numOfSet == 0)
//		numOfSet++;
//	if (sixAndNineExist && sixAndNine)
//		numOfSet++;
//
//	cout << numOfSet << endl;
//
//	return 0;
//}