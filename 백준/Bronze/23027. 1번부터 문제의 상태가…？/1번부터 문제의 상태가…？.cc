#include<iostream>
#include<string>
using namespace std;

int main(void){
    string input;

    cin>>input;

    if(input.find('A')!=string::npos){
        //input.replace(input.find('B'), 1, "A");
        for(int i=0;i<input.size();i++){
            if(input[i]=='B'||input[i]=='C'||input[i]=='D'||input[i]=='F'){
                input[i]='A';
            }
        }
    }
    else if(input.find('B')!=string::npos){
        for(int i=0;i<input.size();i++){
            if(input[i]=='C'||input[i]=='D'||input[i]=='F'){
                input[i]='B';
            }
        }
    }
    else if(input.find('C')!=string::npos){
        for(int i=0;i<input.size();i++){
            if(input[i]=='D'||input[i]=='F'){
                input[i]='C';
            }
        }
    }
    else{
        for(int i=0;i<input.size();i++){
            input[i]='A';
        }
    }

    cout<<input<<"\n";
    
    return 0;
}