#include <iostream>
#include <stack>

using namespace std;

/*
	정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 다섯 가지이다.

	1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
	2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
	3: 스택에 들어있는 정수의 개수를 출력한다.
	4: 스택이 비어있으면 1, 아니면 0을 출력한다.
	5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
*/

int main(void) {
	int commandNum;
	int command;
	stack<int> input;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> commandNum;

	for (int i = 0; i < commandNum; i++) {
		cin >> command;

		switch (command)
		{
		case 1:
			int stackIn;
			cin >> stackIn;
			input.push(stackIn);

			break;

		case 2:
			if (input.size() != 0) {
				cout << input.top() << '\n';
				input.pop();
			}
			else {
				cout << -1 << '\n';
			}

			
			break;

		case 3:
			cout << input.size() << '\n';
			break;

		case 4:
			if (input.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
			break;
		
		case 5:
			if (input.size() != 0) {
				cout << input.top()<<'\n';
			}
			else {
				cout << -1 << '\n';
			}
			break;

		default:
			break;
		}
	}


	return 0;
}