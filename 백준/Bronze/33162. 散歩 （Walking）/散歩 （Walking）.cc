#include <iostream>
using namespace std;

int main(){
    int X;
    cin >> X;
    
    int result = 0;
    if (X % 2 == 0) {
        // 짝수번의 행동이면, 순전진은 X/2 m
        result = X / 2;
    } else {
        // 홀수번의 행동이면, 순전진은 (X-1)/2 + 3 m
        result = (X / 2) + 3;
    }
    
    cout << result;
    return 0;
}
