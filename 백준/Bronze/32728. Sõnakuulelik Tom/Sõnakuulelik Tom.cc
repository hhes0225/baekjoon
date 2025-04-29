#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    string toys;
    cin >> toys;
    
    vector<char> A, B, C; // 각 박스에 담긴 장난감 리스트
    
    for (char toy : toys) {
        vector<vector<char>*> boxes; // 박스 포인터 순서
        if (toy == 's') { // 파란색
            boxes = {&A, &B, &C};
        } else if (toy == 'r') { // 초록색
            boxes = {&B, &C, &A};
        } else if (toy == 'p') { // 빨간색
            boxes = {&C, &A, &B};
        }

        for (auto box : boxes) {
            if (box->size() < K) { // 아직 공간 있으면
                box->push_back(toy);
                break;
            }
        }
    }
    
    // 결과 출력
    for (auto c : A) cout << c;
    cout << '\n';
    for (auto c : B) cout << c;
    cout << '\n';
    for (auto c : C) cout << c;
    cout << '\n';
    
    return 0;
}
