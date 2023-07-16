#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num;
	int tmpNum;
	int workNum;
	//string strNum;
	//string cpyNum;
	//string tmpNum;
	int cycle = 0;

	cin >> num;
	tmpNum = num;

	while (1) {
		if(num==tmpNum&&cycle>0){
			break;
		}

		cycle++;

		workNum = tmpNum;
		tmpNum = num;
		tmpNum = (workNum % 10) * 10;
		tmpNum += (workNum / 10 + workNum % 10) % 10;
	}

	cout << cycle << '\n';


	return 0;
}