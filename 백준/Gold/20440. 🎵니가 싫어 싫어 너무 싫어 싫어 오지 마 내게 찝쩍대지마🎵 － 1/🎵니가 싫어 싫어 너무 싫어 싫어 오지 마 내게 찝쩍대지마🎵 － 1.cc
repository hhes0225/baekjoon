#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
pair<int,int> arr[1000002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr, arr + N);

	
	priority_queue<int> pq;
	int cnt = 0;
	int cnt_max = -987654321;
	int strTime = -987654321, endTime = -987654321;
	for (int i = 0; i < N; i++) {
		pq.push(-arr[i].second);
		cnt++;
		
		//pq가 비지 않았고, 모기가 가장 빨리 나가는 시간이 현재 들어오는 시간보다 작다면 pop
		while (!pq.empty() && -pq.top() <= arr[i].first) {
			pq.pop(); cnt--;
		}

		if (cnt > cnt_max) {
			strTime = arr[i].first;
			endTime = -pq.top();
			cnt_max = cnt;
			int idx = i;
			while (i + 1 != N && arr[i].second == arr[i + 1].first) endTime = arr[++i].second;
		}
	}

	cout << cnt_max << "\n";
	cout << strTime << " " << endTime << "\n";
}