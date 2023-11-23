#include <iostream>
#include <queue>

using namespace std;

/*
	요세푸스 문제는 다음과 같다.

	1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
	이제 순서대로 K번째 사람을 제거한다. 
	한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
	이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
	원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
	예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

	N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
*/

queue<int> numbers;
int k, n;

void JosephusProblem() {
	int i = 1;

	//큐가 빌때까지
	while (!numbers.empty()) {
		if (i % n == 0) {//n번째에 도달하면
			if (numbers.size() == 1) {//마지막 원소면
				cout << numbers.front();
			}
			else {
				cout << numbers.front() << ", ";
			}
			
			numbers.pop();
			i = 0;
		}
		else {//그렇지 않으면
			numbers.push(numbers.front());
			numbers.pop();

		}
		
		i++;//여기서 i가 자동으로 1이 되므로 i=1로 맞출 필요가 없음
	}
}

int main(void) {
	cin >> k >> n;

	for (int i = 1; i <= k; i++) {
		numbers.push(i);
	}

	cout << "<";
	JosephusProblem();
	cout << ">\n";

	return 0;
}