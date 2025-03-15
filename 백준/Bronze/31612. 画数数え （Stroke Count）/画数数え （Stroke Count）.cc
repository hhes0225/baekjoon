#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N;  // 문자열 길이 입력
    cin >> S;  // 문자열 입력
    
    int stroke_count = 0;
    
    // 각 문자의 획수를 더함
    for (char c : S) {
        if (c == 'j' || c == 'i') {
            stroke_count += 2;  // 'j'와 'i'는 2획
        } else if (c == 'o') {
            stroke_count += 1;  // 'o'는 1획
        }
    }
    
    cout << stroke_count << endl;  // 결과 출력
    return 0;
}
