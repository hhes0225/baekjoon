#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

/*
	k와 r의 상대적 위치에 따라 ㅋㅋㄹㅋㅋ 문자열 길이 달라짐.
 	가장 긴 ㅋㅋㄹㅋㅋ 문자열 찾기:
  	R 범위 조정하며 K 개수 확인해야 함.

    	->투포인터
     	(부분 수열, 부분 배열, 특정 범위의 계산)
*/

string input;

//해당 인덱스 기준 왼쪽에 있는 k 개수와, 오른쪽에 있는 k 개수 저장 
int left_k_cnt[3000005];
int right_k_cnt[3000005];

//r이 있는 위치 저장
vector<int> r_indexs;

int main()
{
	cin >> input;

	//인덱스 i 왼쪽에 몇 개의 k 가 존재하는가?
	int k_cnt = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'K') {
			k_cnt++;
			continue;
		}

		r_indexs.push_back(i);
		left_k_cnt[i] = k_cnt;
	}

	//인덱스 i 오른쪽에 몇 개의 k가 존재하는가?
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

		//left기준 왼쪽의 k 개수와, right기준 오른쪽의 k 개수 확인
		int k_cnt1 = left_k_cnt[r_indexs[left]];
		int k_cnt2 = right_k_cnt[r_indexs[right]];

		//right - left + 1 : 가운데 있는 r의 개수
		//min(k_cnt1, k_cnt2) * 2: 현재 양 끝에서 사용할 수 있는 최소 K
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
