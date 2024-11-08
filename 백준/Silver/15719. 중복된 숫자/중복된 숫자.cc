#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

#define MIN 0;
#define MAX 2147483647; 
#define DIV 0

using namespace std;
typedef unsigned long long int ll;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, temp1, temp2, res = 0;
	cin >> n;
	temp1 = (n - 1) * n / 2; // 1) 값 구하기
	for (int i = 0; i < n; i++)
	{
		cin >> temp2;
		res += temp2; // 2) 값 구하기
	}
	cout << res - temp1;
}