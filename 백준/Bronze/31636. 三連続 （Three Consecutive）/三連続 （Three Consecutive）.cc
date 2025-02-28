#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    if(S.find("ooo") != string::npos)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    
    return 0;
}
