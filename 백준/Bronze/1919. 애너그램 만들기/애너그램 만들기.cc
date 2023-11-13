#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	boj1919
	두 영어 단어가 철자의 순서를 뒤바꾸어 같아질 수 있을 때, 그러한 두 단어를 서로 애너그램 관계에 있다고 한다. 
	예를 들면 occurs 라는 영어 단어와 succor 는 서로 애너그램 관계에 있는데, 
	occurs의 각 문자들의 순서를 잘 바꾸면 succor이 되기 때문이다.

	한 편, dared와 bread는 서로 애너그램 관계에 있지 않다. 
	하지만 dared에서 맨 앞의 d를 제거하고, bread에서 제일 앞의 b를 제거하면, 
	ared와 read라는 서로 애너그램 관계에 있는 단어가 남게 된다.

	두 개의 영어 단어가 주어졌을 때, 
	두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 
	문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.
*/

int main(void) {
	string str1, str2;
	int remove;
	int duplicate=0;
	string longer, shorter;

	cin >> str1 >> str2;

	if (str1.size() > str2.size()) {
		longer = str2;
		shorter = str1;
	}
	else {
		longer = str1;
		shorter = str2;
	}


	for (int i = 0; i < longer.size(); i++) {
		if (shorter.find(longer[i]) != string::npos && longer[i]!='0') {//두 문자열 모두 해당 문자가 있으면
			shorter[shorter.find(longer[i])] = '0';
			longer[i] = '0';
			duplicate += 2;
		}
		else {//없으면
			continue;
		}
	}

	remove = longer.size() + shorter.size() - duplicate;

	cout << remove << '\n';

	return 0;
}