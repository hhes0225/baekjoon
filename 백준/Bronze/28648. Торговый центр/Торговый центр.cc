#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int earliest = 1e9; // 매우 큰 초기값

    for(int i = 0; i < n; i++){
        int t, l;
        cin >> t >> l;
        earliest = min(earliest, t + l); // 각 버스의 도착 시간과 비교
    }
    
    cout << earliest << "\n";
    return 0;
}
