#include<iostream>
#include<string>
#include<vector>

using namespace std;

//첫 번째 줄에는 종민이의 영어 이름 A가 주어진다.
//두 번째 줄에는 '그녀'의 영어 이름 B가 주어진다.
//
//A와 B 모두 알파벳 대문자로만 이루어진 길이 2 이상 2000 이하의 문자열이며, 둘의 길이가 같음이 보장된다.
//이름 궁합을 볼 때는 A의 첫 글자를 먼저 쓴다고 하자.
//
//최 그 종 녀 민 -> 이름 점 보는 식으로 영어 획수로 적용하는거

//오답노트
//- INPUT
//	EO
//	EF
//- OUTPUT
//	108 (정답은 8)

vector<int> tabulation(vector<int> love) {
	int tmpInt;
	vector<int> add;

	while (1) {

		for (int i = 1; i < love.size(); i++) {
			tmpInt = love[i - 1] + love[i];

			if (tmpInt >= 10) {//범위 잘못지정해줌!! 10 이상으로 해야 하는데 10 초과로 함..
				tmpInt %= 10;
			}

			add.push_back(tmpInt);
		}

		love = add;
		add.clear();

		/*for (int i = 0; i < love.size(); i++) {
			cout << love[i];
		}

		cout << '\n';*/

		if (love.size() == 2) {
			break;
		}
	}

	return love;
	
}

int main(void) {
	string jName, herName;
	string initNames="";
	int strToStroke;
	vector<int> tmp;
	vector<int> lovePercent;

	cin >> jName >> herName;

	//종민과 그녀의 이름을 번갈아가면서 하나의 문자열로 만들기
	for (int i = 0; i < jName.size(); i++) {
		initNames += jName[i];
		initNames += herName[i];
	}

	//초기 vector
	for (int i = 0; i < initNames.size(); i++) {
		if (initNames[i] == 'A' || initNames[i] == 'E' || initNames[i] == 'F' || initNames[i] == 'H' || initNames[i] == 'I') {
			strToStroke = 3;
			tmp.push_back(strToStroke);
		}
		else if (initNames[i] == 'B' || initNames[i] == 'D' || initNames[i] == 'G' || initNames[i] == 'J' || initNames[i] == 'K' ||
			initNames[i] == 'M' || initNames[i] == 'N' || initNames[i] == 'P' || initNames[i] == 'Q' || initNames[i] == 'R' ||
			initNames[i] == 'T' || initNames[i] == 'X' || initNames[i] == 'Y') {
			strToStroke = 2;
			tmp.push_back(strToStroke);
		}
		else {
			strToStroke = 1;
			tmp.push_back(strToStroke);
		}
	}

	lovePercent =tabulation(tmp);

	for (int i = 0; i < lovePercent.size(); i++) {
		//if (i == 0 && lovePercent[i] == 0) {
		//	continue;
		//	//10의 자리에 0이 있을 경우 생략
		//}
		//(십의 자리가 0이어도 두 자리로 출력한다)

		cout << lovePercent[i];
	}

	cout << '\n';

	return 0;
}

//획수 표로보기
class Alphabet {
public:
	int A = 3, B = 2, C = 1;
	int D = 2, E = 3, F = 3;
	int G = 2, H = 3, I = 3;
	int J = 2, K = 2, L = 1;
	int M = 2, N = 2, O = 1;
	int P = 2, Q = 2, R = 2;
	int S = 1, T = 2, U = 1;
	int V = 1, W = 1, X = 2;
	int Y = 2, Z = 1;
};