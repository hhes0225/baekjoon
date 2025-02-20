#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int solved = 0;
    
    for (int i = 0; i < n; i++){
        string results;
        cin >> results;
        bool isSolved = false;
        // 각 행의 제출 결과에서 '+'가 있는지 확인
        for (char ch : results){
            if (ch == '+'){
                isSolved = true;
                break;
            }
        }
        if (isSolved)
            solved++;
    }
    
    cout << solved << "\n";
    return 0;
}
