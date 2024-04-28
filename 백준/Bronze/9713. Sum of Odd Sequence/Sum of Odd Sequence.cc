#include<iostream>
using namespace std;

int main(void){
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;
        int sum=0;
        
        for(int j=1;j<=input;j+=2){
            sum+=j;
        }

        cout<<sum<<"\n";
    }
    
    return 0;
}