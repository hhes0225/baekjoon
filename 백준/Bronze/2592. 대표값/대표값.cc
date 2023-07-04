#include <iostream>
#include <unordered_map>
#include <vector>
#define tCase 10

using namespace std;

int main(void) {
	int tmp;
	int sum=0;
	int average = 0;
	int max = 0;
	int mostFreq = 0;
	unordered_map<int, int> freq;

	for (int i = 0; i < tCase; i++) {
		cin >> tmp;
		sum += tmp;

		if (freq.find(tmp) != freq.end()) {//있으면
			freq[tmp]++;
		}
		else {
			freq.insert(make_pair(tmp, 1));
		}
	}

	for(auto it=freq.begin();it!=freq.end();it++){
		if (it->second > max) {
			max = it->second;
			mostFreq = it->first;
		}
	}

	average = sum / tCase;

	cout << average << '\n' << mostFreq << '\n';


	return 0;
}