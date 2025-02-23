#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z; // 전체 A, C, E 기준의 개수
    
    int a, c, e;
    cin >> a >> c >> e; // 학생이 충족한 A, C, E 기준의 개수
    
    // A: 모든 기준 충족
    if(a == x && c == y && e == z)
        cout << "A" << endl;
    // B: 모든 E와 C 기준 충족, 그리고 A 기준의 절반 이상 충족
    else if(e == z && c == y && a >= (x + 1) / 2)
        cout << "B" << endl;
    // C: 모든 E와 C 기준 충족
    else if(e == z && c == y)
        cout << "C" << endl;
    // D: 모든 E 기준 충족, 그리고 C 기준의 절반 이상 충족
    else if(e == z && c >= (y + 1) / 2)
        cout << "D" << endl;
    // 그 외에는 E
    else
        cout << "E" << endl;
    
    return 0;
}
