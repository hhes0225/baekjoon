#include <iostream>
#include <string>
using namespace std;

int main() {
    int tCase;
    
    cin>>tCase;

    for(int i=0;i<tCase*5;i++){
        if(i<tCase*4){
            for(int j=0;j<tCase;j++){
                cout<<"@";
            }
            cout<<"\n";
        }
        else{
            for(int j=0;j<tCase*5;j++){
                cout<<"@";
            }
            cout<<"\n";
        }
    }
    
    return 0;
}