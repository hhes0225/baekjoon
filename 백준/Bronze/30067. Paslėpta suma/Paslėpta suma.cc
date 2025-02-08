#include <iostream>
using namespace std;

int main() {
    // 10개의 숫자를 입력받습니다.
    long long nums[10];
    long long total = 0;
    
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
        total += nums[i];
    }
    
    // 전체 합을 2로 나눈 결과가 숨겨진 합입니다.
    cout << total / 2 << endl;
    
    return 0;
}
