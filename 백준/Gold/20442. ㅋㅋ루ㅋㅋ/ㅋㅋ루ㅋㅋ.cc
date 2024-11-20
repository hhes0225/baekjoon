#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string input;

//해당 인덱스 기준 왼쪽에 있는 k 개수와, 오른쪽에 있는 k 개수 저장 
int left_k_cnt[3000005];
int right_k_cnt[3000005];

//r이 있는 위치 저장
vector<int> r_indexs;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> input;

	int k_cnt = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'K') {
			k_cnt++;
			continue;
		}

		r_indexs.push_back(i);
		left_k_cnt[i] = k_cnt;
	}

	k_cnt = 0;
	for (int i = input.size() - 1; i >= 0; i--) {
		if (input[i] == 'K') {
			k_cnt++;
			continue;
		}

		right_k_cnt[i] = k_cnt;
	}

	//중간에서 만나는 투 포인터를 이용
	int left = 0;
	int right = r_indexs.size() - 1;
	int result = 0;
	while (left <= right) {

		//left기준 왼쪽의 k 개수와, right기준 오른쪽의 k 개수를 구한다
		int k_cnt1 = left_k_cnt[r_indexs[left]];
		int k_cnt2 = right_k_cnt[r_indexs[right]];

		//right - left + 1 : 가운데 있는 r의 개수
		result = max(result, right - left + 1 + (min(k_cnt1, k_cnt2) * 2));

		//왼쪽의 k가 더 많을때
		if (k_cnt1 > k_cnt2) {
			right--;
		}

		//오른쪽의 k가 더 많을때
		else {
			left++;
		}

	}

	cout << result;

	return 0;
}