#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int s;
	vector<int> exclude;
	int include;

	cin >> s;

	for (int i = 0; i < s; i++) {
		int input;

		cin >> input;

		exclude.push_back(input);
	}

	cin >> include;

	sort(exclude.begin(), exclude.end());

	int begin = 0, end = 0;

	for (int i = 0; i < exclude.size(); i++) {
		if (exclude[i] < include) {
			begin = exclude[i];
		}
		else if (exclude[i] == include) {
			cout << "0\n" << endl;
			return 0;
		}
		else {
			end = exclude[i];
			break;
		}
	}

	begin++;
	end--;

	int pairs = 0;

	for (int i = begin; i < end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if(i<=include && include<=j){
				//cout << i << " to " << j << endl;
				pairs++;
			}
		}
	}

	cout << pairs << endl;

	return 0;
}