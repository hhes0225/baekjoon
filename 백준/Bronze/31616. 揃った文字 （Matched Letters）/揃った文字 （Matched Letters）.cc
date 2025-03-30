#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    bool allSame = true;
    // 첫 번째 문자를 기준으로 나머지 문자들을 확인합니다.
    for (int i = 1; i < N; i++){
        if (S[i] != S[0]){
            allSame = false;
            break;
        }
    }
    
    if (allSame)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}
