#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin>>input;
    bool isPel = true;
    
    for(int i=0;i<input.size()/2;i++){
        if(input[i]!=input[input.size()-i-1]){
            isPel=false;
            break;
        }
        
    }

    if(isPel){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
    
    return 0;
}