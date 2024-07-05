#include <iostream>
#include <string>
using namespace std;

int main() {
    int tCase;

    cin>>tCase;
    cin.ignore();

    for(int i=0;i<tCase;i++){
        string input;
        int hundred=0;
        
        getline(cin, input);

        for(int i=0;i<input.size();i++){
            if(input[i]==' '){
                continue;
            }
            
            hundred+=(int)input[i]-(int)'A'+1;
        }

        if(hundred==100){
            cout<<"PERFECT LIFE"<<"\n";
        }
        else{
            cout<<hundred<<"\n";
        }
    }
    
    return 0;
}