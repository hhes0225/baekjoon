#include <iostream>
#include <string>

using namespace std;

/*
	boj6550
	2개의 문자열 s와 t가 주어졌을 때 s가 t의 부분 문자열인지 판단하는 프로그램을 작성하라. 
	부분 문자열을 가지고 있는지 판단하는 방법은 t에서 몇 개의 문자를 제거하고 이를 순서를 바꾸지 않고 
	합쳤을 경우 s가 되는 경우를 이야기 한다.

	person compression -> NO
	VERDI vivaVittorioEmanueleReDiItalia -> YES
	
	처음에는 이미 찾은 곳 앞에는 찾지 않으려고 인덱스로 접근하려고 했는데 그러면 애매해져서
	그냥 subarray로 찾은 곳 앞부분은 아예 제거함

*/

int main(void) {
	string input, compare;
	string tmp;
	
	
	while(cin >> input >> compare){
		int lastIndex = -1;
		bool isSubString = true;


		for (int i = 0; i < input.size(); i++) {

			if (compare.find(input[i]) != string::npos) {

				//if (lastIndex < compare.find(input[i])) {
				//	lastIndex = compare.find(input[i]);
				//}
				//else {
				//	//cout << i << "에서 false - index가 크지 않음" << endl;
				//	isSubString = false;
				//}

				compare = compare.substr(compare.find(input[i])+1, compare.size());
			}
			else {
				//cout << i << "에서 false - 해당 문자 찾지 못함" << endl;
				isSubString = false;
				continue;
			}

			//cout << "바뀐 compare: " << compare << endl;
		}
	

		if (isSubString) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}