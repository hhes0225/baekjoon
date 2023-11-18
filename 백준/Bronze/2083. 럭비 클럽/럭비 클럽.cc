#include <iostream>

using namespace std;

/*
	올 골드 럭비 클럽의 회원들은 성인부 또는 청소년부로 분류된다.
	
	나이가 17세보다 많거나, 몸무게가 80kg 이상이면 성인부이다. 그 밖에는 모두 청소년부이다. 클럽 회원들을 올바르게 분류하라.	
*/

int main(void) {
	string name;
	int age, weight;

	while (1) {
		cin >> name >> age >> weight;

		if (name == "#" && age == 0 && weight == 0) {
			break;
		}


		//나이 17세 이상이거나 80kg 이상이면 성인부
		if (age > 17 || weight >= 80) {
			cout << name << " Senior"<<endl;
		}
		else {
			cout << name << " Junior" << endl;
		}
	}

	return 0;
}