#include<iostream>
#include<vector>

using namespace std;

//다음과 같은 규칙에 따라 수들을 만들려고 한다.
//
//1. 첫 번째 수로 양의 정수가 주어진다.
//2. 두 번째 수는 양의 정수 중에서 하나를 선택한다.
//3. 세 번째부터 이후에 나오는 모든 수는 앞의 앞의 수에서 앞의 수를 빼서 만든다.
//	예를 들어, 세 번째 수는 첫 번째 수에서 두 번째 수를 뺀 것이고, 네 번째 수는 두 번째 수에서 세 번째 수를 뺀 것이다.
//4. 음의 정수가 만들어지면, 이 음의 정수를 버리고 더 이상 수를 만들지 않는다.
//
//첫 번째 수로 100이 주어질 때, 두 번째 수로 60을 선택하여 위의 규칙으로 수들을 만들면 
//7개의 수들 100, 60, 40, 20, 20, 0, 20이 만들어진다.
//그리고 두 번째 수로 62를 선택하여 위의 규칙으로 수들을 만들면 
//8개의 수들 100, 62, 38, 24, 14, 10, 4, 6이 만들어진다.
//위의 예에서 알 수 있듯이, 첫 번째 수가 같더라도 두 번째 수에 따라서 만들어지는 수들의 개수가 다를 수 있다.
//
//입력으로 첫 번째 수가 주어질 때, 이 수에서 시작하여 위의 규칙으로 만들어지는 
//최대 개수의 수들을 구하는 프로그램을 작성하시오.
//최대 개수의 수들이 여러 개일 때, 그중 하나의 수들만 출력하면 된다.


int main(void) {
	int num1;
	int maxCount = 0;
	int maxNum2=1;
	int substract1, substract2;

	cin >> num1;

	//틀린 이유 - 범위를 num2<num1이 아니라 num2<=num1로 했어야 함
	//input :
	//1
	
	//output :
	//0
	//1 1 0 1
	    
	//correct ans :
	//4
	//1 1 0 1
	for (int num2 = 1; num2 <= num1; num2++) {
		int tmpCount = 0;
		substract1 = num1;
		substract2 = num2;

		while (1) {
			//cout << substract1 << " " << substract2 << endl;
			if (substract1 < 0 || substract2 < 0) {
				tmpCount++;//마지막게 반영이 안돼서 반영한것임
				//cout << "escape\n";
				break;
			}
			else {
				tmpCount++;
				//cout << "tmpCount: " << tmpCount << endl;
			}

			int tmpSave = substract1;
			substract1 = substract2;
			substract2 = tmpSave - substract2;

			
		}

		if (max(maxCount, tmpCount) == tmpCount) {
			maxNum2 = num2;
		}
		maxCount = max(maxCount, tmpCount);

		//cout << endl << endl;

	}


	cout << maxCount << '\n';
	//cout << maxNum2 << '\n';

	substract1 = num1;
	substract2 = maxNum2;

	//cout << substract1 << " ";

	while (1) {
		//cout << substract1 << " " << substract2 << endl;
		if (substract1 < 0 || substract2 < 0) {
			cout << substract1 << "\n";//마지막 substract1이 반영이 안돼서 수동으로 넣어줌
			break;
		}
		else {
			cout << substract1 << " ";
			//cout << "tmpCount: " << tmpCount << endl;
		}

		int tmpSave = substract1;
		substract1 = substract2;
		substract2 = tmpSave - substract2;
	}

	return 0;
}
