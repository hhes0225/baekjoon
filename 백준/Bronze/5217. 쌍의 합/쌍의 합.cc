#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;
        
        cout<<"Pairs for "<<input<<": ";
        
        for(int j=1;j<=input/2;j++){
            int pair = input-j;
            if(pair==j){
                break;
            }
            if(pair<j){
                break;
            }

            if(j>1){
                cout<<", ";
            }
            
            cout<<j<<" "<<pair;
            
        }
        cout<<endl;
    }
    
    return 0;
}