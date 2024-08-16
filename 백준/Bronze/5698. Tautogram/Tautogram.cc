#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input;

    while(1){
        getline(cin, input);
        string initial="";
        bool isTautogram=true;

        if(input=="*"){
            break;
        }

        //대문자면 소문자로
        for(int i=0;i<input.size();i++){
            if(input[i]>='A' && input[i]<='Z'){
                input[i]=input[i]-'A'+'a';
            }
        }

        initial+=input[0];
        for(int i=1;i<input.size();i++){
            if(input[i]==' '){
                initial+=input[i+1];
            }
        }
        //cout<<initial<<endl;

        for(int i=1;i<initial.size();i++){
            if(initial[i-1]!=initial[i]){
                isTautogram=false;
                break;
            }
        }

        if(isTautogram){
            cout<<"Y\n";
        }
        else{
            cout<<"N\n";
        }
    }
    
    return 0;
}