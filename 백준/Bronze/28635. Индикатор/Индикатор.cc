#include <iostream>
using namespace std;

int main(){
    int m, a, b;
    cin >> m >> a >> b;
    
    // a에서 b로 가기 위해 오른쪽(증가) 방향으로 눌러야 하는 횟수
    int presses = (b >= a) ? (b - a) : (m - (a - b));
    
    cout << presses << "\n";
    return 0;
}
