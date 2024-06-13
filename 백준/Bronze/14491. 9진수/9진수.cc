#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int input;
    string nine="";
    
    cin>>input;

    while(1){
        if(input==0){
            break;
        }

        int tmp = input%9;
        input/=9;
        nine += to_string(tmp);
    }

    reverse(nine.begin(), nine.end());

    cout<<nine<<"\n";
    
    return 0;
}