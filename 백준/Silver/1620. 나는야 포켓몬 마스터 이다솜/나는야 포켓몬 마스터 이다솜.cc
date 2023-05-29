#include<iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	/*
		맵=딕셔너리에서 찾는 법
		1. key로 value 찾기 = map의 메서드인 find(key) 사용
		2. value로 key 찾기 = 순회하면서 사용
		이때, 숫자 범위 내라면(>='0' && <='9') 숫자 변환 함수인 stoi 사용
		stoi <---> to_string
	*/
	//이 두문장 없으면 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dictNum, questionNum;
	string tmpStr;
	vector<string> namelist;
	map<string, int> pokemonDict;
	vector<string> qna;

	cin >> dictNum >> questionNum;


	for (int i = 0; i < dictNum; i++) {
		cin >> tmpStr;

		pokemonDict.insert(make_pair(tmpStr, i+1));
		namelist.push_back(tmpStr);
	}

	for (int i = 0; i < questionNum; i++) {
		cin >> tmpStr;
		if (tmpStr[0] >= 'A'&& tmpStr[0]<='Z') {
			cout << pokemonDict[tmpStr] << "\n";
			//qna.push_back(to_string(pokemonDict[tmpStr]));
		}
		else {
			
			cout << namelist[stoi(tmpStr) - 1] << "\n";
			//qna.push_back(namelist[stoi(tmpStr)-1]);
		}
	}

	/*for (int i = 0; i < qna.size(); i++) {
		cout << qna[i] << '\n';
	}*/


	return 0;
}