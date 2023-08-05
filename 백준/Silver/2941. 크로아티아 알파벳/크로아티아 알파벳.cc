#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	string parse;
	int numOfChar = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input;

	numOfChar = input.size();
	//cout << "size:" << numOfChar<<endl;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '=') {
			if (i - 2 >= 0) {
				//cout << input.substr(i - 2, 2) << endl;
				if (input.substr(i - 2, 2) == "dz") {
					numOfChar -= 2;
				}
				else {
					numOfChar--;
					//cout << "감소" << endl;
				}
			}
			else {
				//cout << "감소2" << endl;
				numOfChar--;
			}
			
		}
		else if (input[i] == '-') {
			numOfChar--;
		}
		else if (input[i] == 'j') {
			if (input[i - 1] == 'l' || input[i - 1] == 'n') {
				numOfChar--;
			}
		}
		else {
			continue;
		}
	}


	cout << numOfChar << '\n';

	return 0;
}

//맞긴 한데 모든 케이스를 체크해서 시간초과 발생
// 이를 해결하기 위해서는 규칙성을 발견해서 그거를 체크해야됨
//int main(void) {
//	string input;
//	string parse;
//	int numOfChar = 0;
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> input;
//
//
//	/*for (int i = 0; i < input.size(); i++) {
//		
//		if (input[i] == 'c') {
//			if (input[i + 1] == '=' || input[i + 1] == '-') {
//				numOfChar++;
//			}
//		}
//		else if (input.substr(i, 3) == "dz=") {
//			numOfChar++;
//		}
//	}*/
//
//	int i = 0;
//
//	while (1) {
//		if (i >= input.size()) {
//			break;
//		}
//
//		if (input[i] == 'c') {
//			if (input[i + 1] == '=' || input[i + 1] == '-') {
//				//cout << "c=-" << endl;
//				numOfChar++;
//				i += 2;
//				continue;
//			}
//		}
//		else if (input.substr(i, 3) == "dz=") {
//			//cout << "dz=" << endl;
//			numOfChar++;
//			i += 3;
//			continue;
//		}
//		else if (input.substr(i, 2) == "d-") {
//			//cout << "d-" << endl;
//			numOfChar++;
//			i += 2;
//			continue;
//		}
//		else if (input.substr(i, 2) == "lj"|| input.substr(i, 2) == "nj") {
//			//cout << "lj/nj" << endl;
//			numOfChar++;
//			i += 2;
//			continue;
//		}
//		else if (input.substr(i, 2) == "s=" || input.substr(i, 2) == "z=") {
//			//cout << "s=/z=" << endl;
//			numOfChar++;
//			i += 2;
//			continue;
//		}
//		else {
//			//cout << input[i] << endl;
//			numOfChar++;
//			i++;
//			continue;
//		}
//
//
//	}
//
//	cout << numOfChar << '\n';
//
//	return 0;
//}