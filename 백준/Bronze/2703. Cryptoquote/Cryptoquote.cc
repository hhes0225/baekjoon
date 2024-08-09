#include <iostream>
#include <string>

using namespace std;

int main(void){
    int tCase;
    string input;
    //char crypto[26];
    string crypto;
    
    cin>>tCase;
    cin.ignore();
    
    for(int i=0;i<tCase;i++){
        getline(cin, input);
        getline(cin, crypto);

        for(int j=0;j<input.size();j++){
            if(input[j]!=' '){
                input[j]=crypto[input[j]-'A'];
            }
        }

        cout<<input<<"\n";
    }
}