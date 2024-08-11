#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input;
    string notMirror="acefghjklmnrstuyz";

    while(1){
        bool validity=true;
        string tmp="";
        cin>>input;

        if(input=="#"){
            break;
        }

        for(int i=0;i<input.size();i++){
            //거울상 관계가 아닌 문자가 input 내에 있으면
            if(notMirror.find(input[i])!=string::npos){
                cout<<"INVALID\n";
                validity=false;
                break;
            }
        }

        if(!validity){
            continue;
        }
        
        reverse(input.begin(), input.end());

        for(int i=0;i<input.size();i++){
            if(input[i]=='b'){
                tmp+='d';
            }
            else if(input[i]=='d'){
                tmp+='b';
            }
            else if(input[i]=='p'){
                tmp+='q';
            }
            else if(input[i]=='q'){
                tmp+='p';
            }
            else{
                tmp+=input[i];
            }
        }

        cout<<tmp<<"\n";

        
    }
    
    return 0;
}