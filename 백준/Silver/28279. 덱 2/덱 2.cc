#include <iostream>
#include <deque>

using namespace std;

deque<int> input;

void dequeFunc(int command) {
	int x;

	/*if(command!=2 && command !=1)
		cout << "output: ";*/
	switch (command) {
	case 1: cin >> x; input.push_front(x);  break;
	case 2: cin >> x; input.push_back(x); break;
	case 3: 
		if (!input.empty()) {
			cout << input.front()<<"\n";
			input.pop_front();
		}
		else {
			cout << "-1\n";
		} 
		break;
	case 4: 
		if (!input.empty()) {
			cout << input.back()<<"\n";
			input.pop_back();
		}
		else {
			cout << "-1\n";
		}
		break;
	case 5: cout << input.size() << "\n"; break;
	case 6:
		if (input.empty()) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
		break;
	case 7: 
		if (!input.empty()) {
			cout << input.front() << "\n";
		}
		else {
			cout << "-1\n";
		}
		break;
	case 8: 
		if (!input.empty()) {
			cout << input.back() << "\n";
		}
		else {
			cout << "-1\n";
		}
		break;
	}
}

int main(void) {
	int tCase;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int command;
		cin >> command;

		dequeFunc(command);
	}

	return 0;
}