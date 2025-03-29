#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    // 0부터 9까지 숫자의 등장 여부를 저장할 배열 (초기값 false)
    bool present[10] = { false };
    
    // 수열 A의 각 원소를 읽으면서 해당 숫자 등장 표시
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        present[x] = true;
    }
    
    // 0부터 9까지 오름차순으로 순회하면서, 등장한 숫자 출력
    for(int i = 0; i < 10; i++){
        if(present[i])
            cout << i << "\n";
    }
    
    return 0;
}
