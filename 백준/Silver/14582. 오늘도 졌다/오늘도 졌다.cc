#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int ulimIn, startIn;
	vector<int>ulimScore, startScore;
	bool isUlimWin = false;
	int ulim = 0, start = 0;

	for (int i = 1; i <= 18; i++) {
		if(i % 2==1){
			cin >> ulimIn;
			ulimScore.push_back(ulimIn);
		}
		else {
			ulimScore.push_back(0);
		}
	}

	for (int i = 1; i <= 18; i++) {
		if(i%2==0){
			cin >> startIn;
			startScore.push_back(startIn);
		}
		else {
			startScore.push_back(0);
		}
	}

	

	for(int i=0;i<18;i++){
		ulim += ulimScore[i];
		start += startScore[i];

		if (ulim > start) {
			//cout << "와 이김 "<<ulimScore[i]<<" "<< startScore[i] << endl;
			isUlimWin = true;
		}
	}

	if (ulim < start && isUlimWin) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}

	return 0;
}