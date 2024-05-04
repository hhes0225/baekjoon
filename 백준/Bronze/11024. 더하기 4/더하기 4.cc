#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    int tCase;
    string input;
    
    
    cin>>tCase;

    cin.ignore();

    for(int i=0;i<tCase;i++){
        getline(cin, input);
        string tmp="";
        int sum=0;
        
        for(int j=0;j<input.size();j++){
            if(input[j]==' '){
                sum+=stoi(tmp);
                tmp="";
            }
            else{
                tmp+=input[j];
            }
        }

        sum+=stoi(tmp);
        
        cout<<sum<<endl;
    }
    
    
    return 0;
}