#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int tCase;
    string input;
    int op1, op2;
    string tmp="";

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        cin>>input;

        if(input=="P=NP"){
            cout<<"skipped\n";
            continue;
        }

        for(int j=0;j<input.size();j++){
            if(input[j]=='+'){
                op1=stoi(tmp);
                tmp="";
            }
            else if(j==input.size()-1){
                tmp +=input[j];
                op2=stoi(tmp);
                tmp="";
            }
            else{
                tmp+=input[j];
            }
            
        }

        cout<<op1+op2<<"\n";
        
    }
    
    
    return 0;
}