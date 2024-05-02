#include<iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int input;
    cin>>input;

    for(int i=0;i<input*5;i++){
        if(i<input){
            for(int j=0;j<input*5;j++){
                cout<<"@";
            }
        }
        else{
            for(int j=0;j<input;j++){
                cout<<"@";
            }
        }

        cout<<endl;
        
    }
    
    return 0;
}