#include<iostream>
#include<string>
using namespace std;

int main(void){
    string input;
    int i=0;
    
    while(getline(cin, input)){
        cout<<input<<"\n";
    }    
    
    return 0;
}