#include <iostream>
#include <string>
using namespace std;


int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string input;
        cin>>input;

        if(input[input.size()/2-1]==input[input.size()/2]){
            cout<<"Do-it\n";
        }
        else{
            cout<<"Do-it-Not\n";
        }
    }
    
    return 0;
}