#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	boj10825
	도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 
	이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

	1. 국어 점수가 감소하는 순서로(큰->작), 역순
	2. 국어 점수가 같으면 영어 점수가 증가하는 순서로(작->큰), 정순
	3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로(큰->작), 역순
	4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (a->z), 정순
	(단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
*/

class Student {
public:
	string name;
	int korean;
	int english;
	int math;
};

bool compare(Student a, Student b) {
	if (a.korean != b.korean)
		return a.korean > b.korean;
	else if (a.english != b.english)
		return a.english < b.english;
	else if (a.math != b.math)
		return a.math > b.math;
	else
		return a.name < b.name;
}

int main(void) {
	int tCase;
	string tmp;
	int tmp1, tmp2, tmp3;
	Student newStu;
	vector<Student> stuList;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp >> tmp1 >> tmp2 >> tmp3;

		newStu.name = tmp;
		newStu.korean = tmp1;
		newStu.english = tmp2;
		newStu.math = tmp3;

		stuList.push_back(newStu);
	}

	sort(stuList.begin(), stuList.end(), compare);

	//cout << "\n";

	for (int i = 0; i < stuList.size(); i++) {
		//cout << stuList[i].name << " " << stuList[i].korean << " " << stuList[i].english << " " << stuList[i].math << "\n";
		cout << stuList[i].name << "\n";
	}

	return 0;
}