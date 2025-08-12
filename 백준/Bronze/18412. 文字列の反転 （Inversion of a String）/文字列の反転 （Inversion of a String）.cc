#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B;
    string S;
    
    // 입력 받기
    cin >> N >> A >> B;
    cin >> S;
    
    // A, B는 1-based index이므로, 0-based index로 변환
    A--; // A를 0-based index로 조정
    B--; // B를 0-based index로 조정
    
    // 부분 문자열 반전하기
    string part = S.substr(A, B - A + 1); // A번째부터 B번째까지의 부분 문자열
    reverse(part.begin(), part.end()); // 부분 문자열 반전
    
    // 새로운 문자열 만들기
    S = S.substr(0, A) + part + S.substr(B + 1);
    
    // 결과 출력
    cout << S << endl;
    
    return 0;
}
