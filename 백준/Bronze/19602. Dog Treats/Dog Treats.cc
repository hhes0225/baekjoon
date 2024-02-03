#include <iostream>

using namespace std;

int main(void){
    int s,m,l;
    int happy;
    
    cin >>s>>m>>l;
    
    happy=s+m*2+l*3;
    
    if(happy>=10){
        cout<<"happy\n";
    }
    else{
        cout<<"sad\n";
    }
    
    return 0;
}