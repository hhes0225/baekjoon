#include <iostream>
#include <string>
using namespace std;

int main(void){
    string input;
    
    cin>>input;
    
    for(int i=0;i<input.size();i++){
        if(input[i]>='A' && input[i]<='C'){
            cout<<(char)('Z'- ('C'-input[i]));
        }
        else 
            cout<<(char)(input[i]-3);
    }
    cout<<endl;
    
    return 0;
}