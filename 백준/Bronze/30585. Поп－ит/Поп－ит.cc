#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    
    int count0 = 0, count1 = 0;
    for (int i = 0; i < h; i++){
        string line;
        cin >> line;
        for (char c : line){
            if(c == '0') count0++;
            else if(c == '1') count1++;
        }
    }
    
    cout << min(count0, count1) << endl;
    return 0;
}
