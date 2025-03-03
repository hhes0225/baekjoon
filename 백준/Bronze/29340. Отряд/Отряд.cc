#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    string ans = "";
    for (int i = 0; i < a.size(); i++){
        // a[i]와 b[i] 중 더 큰 값 선택
        ans += max(a[i], b[i]);
    }
    
    cout << ans << "\n";
    return 0;
}
