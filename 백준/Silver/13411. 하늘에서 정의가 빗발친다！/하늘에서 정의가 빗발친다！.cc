#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void) {
	int missileNum;
	int x, y, speed;
	double time;
	vector<pair<int, double>> missileTime;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> missileNum;

	for (int i = 0; i < missileNum; i++) {
		cin >> x >> y >> speed;

		time = sqrt(pow(x, 2) + pow(y, 2)) / speed;

		missileTime.push_back({ i + 1, time });
	}

	sort(missileTime.begin(), missileTime.end(), compare);

	for (int i = 0; i < missileTime.size(); i++) {
		//cout << missileTime[i].first << ": " << missileTime[i].second << endl;
		cout << missileTime[i].first << '\n';
	}

}