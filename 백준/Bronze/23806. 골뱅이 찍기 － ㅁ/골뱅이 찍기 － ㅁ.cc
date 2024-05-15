#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase*5;i++){

        if(i<tCase){
            for(int j=0;j<tCase*5;j++){
                cout<<"@";
            }
        }
        else if(i>=tCase*5-tCase){
            for(int j=0;j<tCase*5;j++){
                cout<<"@";
            }
        }
        else{
            for(int j=0;j<tCase*5;j++){
                if(j<tCase || j>=tCase*5-tCase){
                    cout<<"@";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<"\n";
        
    }
    
    return 0;
}