#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000
bool isPrime[MAX + 1]; // 소수 여부를 저장하는 배열
int visited[MAX + 1]; // 각 소수가 사용된 횟수를 저장하는 배열

// 에라토스테네스의 체를 사용하여 소수를 구하는 함수
void SieveOfEratosthenes() {
    for (int i = 2; i <= MAX; i++) {
        isPrime[i] = true; // 처음에 모두 소수라고 가정
    }
    for (int i = 2; i * i <= MAX; i++) { // 2부터 sqrt(MAX)까지
        if (!isPrime[i]) continue; // 이미 지워진 수는 무시
        for (int j = i * i; j <= MAX; j += i) { // 자기 자신을 제외한 배수를 모두
            isPrime[j] = false; // 지운다
        }
    }
}

// 거듭제곱을 계산하는 함수
int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = res * x;
        }
        y /= 2;
        x = x * x;
    }
    return res;
}

int main(void) {
    SieveOfEratosthenes(); // 소수를 구한다
    int n;
    cin >> n; // 숫자의 개수를 입력받는다
    vector<int> plist; // 소수를 저장할 벡터
    for (int i = 1; i <= MAX; i++) if (isPrime[i]) plist.push_back(i); // 소수를 plist에 저장
    vector<vector<int>> v(n, vector<int>(plist.size(), 0)); // 각 숫자에 사용된 소수의 개수를 저장할 2차원 벡터

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score; // 숫자를 입력받는다
        for (int j = 0; j < plist.size(); j++) {
            if (score == 1) break; // 숫자가 1이 되면 더 이상 나눌 필요가 없다
            while (score % plist[j] == 0) { // 소수로 나눌 수 있을 때까지 나눈다
                score /= plist[j];
                visited[plist[j]]++; // 전체 숫자에서 소수의 개수를 증가시킨다
                v[i][j]++; // i번째 숫자에서 소수의 개수를 증가시킨다
            }
        }
    }
    int gcd = 1; // 최대공약수를 저장할 변수
    int cnt = 0; // 연산 횟수를 저장할 변수
    for (int i = 0; i < plist.size(); i++) {
        int d = visited[plist[i]] / n; // 최소로 분배되어야 할 각 소수의 개수
        for (int j = 0; j < n; j++) {
            if (v[j][i] < d) { 
                cnt += d - v[j][i]; // 부족한 소수의 개수를 채운다
            }
        }
        gcd *= power(plist[i], d); // 최대공약수를 계산한다
    }
    cout << gcd << " " << cnt; // 최대공약수와 연산 횟수를 출력한다

    return 0;
}
