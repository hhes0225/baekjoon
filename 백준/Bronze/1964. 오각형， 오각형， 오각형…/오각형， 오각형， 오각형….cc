#include <iostream>

using namespace std;

//오각형이 확장될 때 N단계의 점의 수는 몇개인가?
//N = 1		5
//N = 2	5 + 7 = 12
//N = 3	5 + 7 + 10 = 22
//N = 4	????

//각 변의 점의 수를 체크해야할듯.
//각 회마다 증가하는 변은 3개.
//N = 1 : 0개
//N = 2 : 1개, 증가하는 점의 수는 3 + 2 + 2
//N = 3 : 2개, 증가하는 점의 수는 4 + 3 + 3
//...


int main()
{
	long long int N;
	long long count;

	cin >> N;

	count = (long long)(((3 * N * N) + (5 * N) + 2) / 2);

	cout << count % 45678<< endl;
}