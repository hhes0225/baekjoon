#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//상근이는 세계적인 소프트웨어 회사 기글에서 일한다.
//이 회사의 가장 큰 특징은 자유로운 출퇴근 시간이다.
//따라서, 직원들은 반드시 9시부터 6시까지 회사에 있지 않아도 된다.
//각 직원은 자기가 원할 때 출근할 수 있고, 아무때나 퇴근할 수 있다.
//상근이는 모든 사람의 출입카드 시스템의 로그를 가지고 있다.
//이 로그는 어떤 사람이 회사에 들어왔는지, 나갔는지가 기록되어져 있다.
//로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램을 작성하시오.

int main(void) {
	int tCase;
	string input;
	string name="";
	string situation="";
	map < string, bool, greater<string>> attend;
	//attend를 string 오름차순으로 정렬하겠다.
	//사실 나중에 벡터에서 정렬되므로 굳이 할필요는 없지만 공부하는 용도로 쓰자
	vector<string> nameSort;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> name >> situation;

		if (situation == "enter") {
			attend.insert(make_pair(name, true));
		}
		else {
			//attend[name] = false;
			attend.erase(name);

			//erase 하니까 맞음. 그냥 false로 하면 에러가 남
		}

	}

	for (auto it = attend.begin(); it != attend.end(); it++) {
		if (it->second == true) {
			nameSort.push_back(it->first);
			//cout << it->first << '\n';
		}
	}
	 
	
	//대소문자 정렬이 안됨

	sort(nameSort.begin(), nameSort.end());
	reverse(nameSort.begin(), nameSort.end());

	for (int i = 0; i < nameSort.size(); i++) {
		cout << nameSort[i] << '\n';
	}


	return 0;
}
