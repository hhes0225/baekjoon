#include <iostream>
using namespace std;
 
int main(){
    int h, l, a, b;
    cin >> h >> l >> a >> b;
    
    // 옵션 1: a 변을 빨랫줄에 걸 경우
    bool option1 = (a <= l) && ((b / 2.0) <= h);
    // 옵션 2: b 변을 빨랫줄에 걸 경우
    bool option2 = (b <= l) && ((a / 2.0) <= h);
    
    if(option1 || option2)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
