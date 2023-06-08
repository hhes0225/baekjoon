#include<iostream>
#include <string>
#include <vector>
#define MAX_CHANNEL 1000000
using namespace std;

int main(void) {
	int goalChannel;
	int brokenNum;
	int tmp;
	vector<int> brokenBtns;

	int currentChannel = 100;
	int clicks = 0;

	int under = MAX_CHANNEL;
	int over = 0;
	int from100;
	int moveChannel;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> goalChannel >> brokenNum;

	for (int i = 0; i < brokenNum; i++) {
		cin >> tmp;
		brokenBtns.push_back(tmp);
	}

	if (currentChannel == goalChannel) {
		cout << clicks << endl;
	}
	else {
		bool escape = true;

		//case 1. under(0~목표채널)

		for (int i = goalChannel; i >= 0; i--) {
			string channelStr = to_string(i);
			//cout << "channelStr= " << channelStr << endl;
			for (int j = 0; j < brokenBtns.size(); j++) {
				if (channelStr.find(to_string(brokenBtns[j]))!=string::npos) {
					//cout << i<<": " << to_string(brokenBtns[j]) << " broken" << endl;
					escape = false;
					break;
				}
			}

			if (escape == true) {
				//cout << "under: " << i << '\n';
				under =i;
				break;
			}
			else {
				escape = true;
			}
		}

		//case 2. over(목표채널~max 채널)

		for (int i = goalChannel+1; i <= MAX_CHANNEL; i++) {
			/*if (goalChannel < 100) {
				break;
			}*/
			string channelStr = to_string(i);
			//cout << "channelStr= " << channelStr << endl;
			for (int j = 0; j < brokenBtns.size(); j++) {
				if (channelStr.find(to_string(brokenBtns[j])) != string::npos) {
					//cout << i << ": " << to_string(brokenBtns[j]) << " broken" << endl;
					escape = false;
					break;
				}
			}

			if (escape == true) {
				//cout << "over: " << i << '\n';
				over = i;
				break;
			}
			else {
				escape = true;
			}
		}

		//case 3. 100에서 출발
		if (goalChannel > 100) {
			from100 = goalChannel - 100;
		}
		else {
			from100 = 100 - goalChannel;
		}

		bool isUnder = false;
		bool isOver = false;

		//cout << "under: " << under << endl;

		//over에서 아무것도 입력할 수 없으면 0이 됨. 따라서 over로 표현할 수 없게 된다면 이 경우는 under로 넘어가기
		//under에서 아무것도 입력할 수 없으면 MAX_CHANNEL이 됨. 따라서 goalChannel-under은 음수가 됨.
		//under로 표현할 수 없게 된다면 over로 넘어가기
		if (((goalChannel - under > over - goalChannel) && (over!=0)) || (under == MAX_CHANNEL)) {
			//cout << "over" << endl;
			moveChannel = over;
			clicks = over - goalChannel + to_string(moveChannel).size();
			isOver = true;
		}
		else {
			//cout << "under" << endl;
			moveChannel = under;
			clicks = goalChannel - under + to_string(moveChannel).size();
			isUnder = true;
		}


		if (clicks > from100 || brokenBtns.size()==10)
			clicks = from100;


		cout << clicks << "\n";

	}

	return 0;
}