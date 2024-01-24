#include <iostream>
#include <string>

using namespace std;

int main(void){
    string input;
    int a, b, c;
    
    getline(cin, input);
    
    a=(int)input[0]-(int)'0';
    b=(int)input[4]-(int)'0';
    c=(int)input[8]-(int)'0';
    
    if(a+b==c)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
    return 0;
}