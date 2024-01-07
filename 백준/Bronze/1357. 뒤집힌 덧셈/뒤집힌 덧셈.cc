#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int rev(int input) {
	string tmp;
	
	tmp = to_string(input);
	reverse(tmp.begin(), tmp.end());
	
	//cout << tmp<<endl;

	return stoi(tmp);
}

int main(void) {
	int x, y;
	int result;

	cin >> x >> y;

	//cout << rev(x)<<" "<<rev(y)<<endl;

	result = rev(rev(x) + rev(y));

	cout << result << "\n";

	return 0;
}