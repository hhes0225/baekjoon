#include <iostream>
using namespace std;


int main() {
    int tCase;
    cin>>tCase;
        
    for(int i=0;i<tCase;i++){
        string input;
        cin>>input;

        for(int j=0;j<input.size();j++){
            if(input[j]=='Z'){
                input[j]='A';
            }
            else{
                input[j]+=1;   
            }
    }
        cout<<"String #"<<i+1<<"\n";
        cout<<input<<"\n\n";
    }
    
    return 0;
}