#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
	int tCase;
	int tmp;
	vector<int> nums;
	unordered_map<int, int> modeMap;
	int sum = 0;
	double arithMean;//산술평균
	int median;//중앙값
	int mode;//최빈값
	int range;//범위

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		nums.push_back(tmp);
		sum += tmp;
	}

	sort(nums.begin(), nums.end());

	/*for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << endl;
	}*/

	//산술평균
	arithMean = (double)sum / nums.size();
	arithMean = round(arithMean);
	if (arithMean == 0) {
		arithMean = 0;
	}


	//중앙값
	if (nums.size() == 1) {
		median = nums[0];
;	}
	else
		median = nums[(nums.size()-1) / 2 ];


	//최빈값
	vector<int> keys;

	if (nums.size() == 1) {
		mode = nums[0];
		modeMap.insert(make_pair(mode, 1));
	}
	else{
		for (int i = 0; i < nums.size(); i++) {
			

			if (i >= 1) {
				//key가 map에 있는지 확인
				if (modeMap.find(nums[i]) != modeMap.end()) {
					modeMap[nums[i]]++;
					//keys.push_back(nums[i]);
					continue;
				}
				else {
					modeMap.insert(make_pair(nums[i], 1));
				}
			}
			else {
				modeMap.insert(make_pair(nums[i], 1));
				//keys.push_back(nums[i]);
			}
		}
	}

	int maxKey=0;
	int maxValue = 0;
	bool isDuplicate;

	//cout << "===" << endl;
	for (auto i = modeMap.begin(); i != modeMap.end(); i++) {
		//cout << i->first << " " << i->second << endl;

		if (i->second > maxValue) {
			maxKey = i->first;
			maxValue = i -> second;
			isDuplicate = false;
			keys.clear();
			keys.push_back(i->first);
		}
		else if (i->second == maxValue) {
			isDuplicate = true;
			keys.push_back(i->first);
		}
	}

	sort(keys.begin(), keys.end());

	//cout << "===" << endl;

	//cout << "isDup: " << isDuplicate << endl;
	/*for (int i = 0; i < keys.size(); i++) {
		cout << "key: " << keys[i] << endl;
	}*/
	

	if (isDuplicate && nums.size()>1) {
		mode = keys[1];
	}
	else {
		mode = maxKey;
	}
	
	
	//범위
	range = nums[nums.size() - 1] - nums[0];


	////결과 출력
	cout << arithMean << endl;
	cout << median << endl;
	cout << mode << endl;
	cout << range << endl;

	return 0;
}