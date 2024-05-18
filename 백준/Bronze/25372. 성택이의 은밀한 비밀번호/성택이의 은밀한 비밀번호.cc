#include <iostream>
#include <string>
using namespace std;



int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string input;
        cin>>input;
        
        int cond = input.size();
        if(cond>=6 && cond <=9){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }

    }
    return 0;
}