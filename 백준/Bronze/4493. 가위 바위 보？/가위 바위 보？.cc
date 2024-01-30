#include<iostream>

using namespace std;

int main(void){
    int tCase;
    int rnd;
    
    cin>>tCase;
    
    for(int i=0;i<tCase;i++){
        cin>>rnd;
        
        int p1=0,p2=0;
        char p1In, p2In;
        
        for(int j=0;j<rnd;j++){
            cin>>p1In>>p2In;
            
            if(p1In==p2In)
                continue;
            else if(p1In=='R'&&p2In=='S')
                p1++;
            else if(p1In=='S'&&p2In=='P')
                p1++;
            else if(p1In=='P'&&p2In=='R')
                p1++;
            else
                p2++;
        }

        if(p1==p2)
            cout<<"TIE\n";
        else if(p1>p2){
            cout<<"Player 1\n";
        }
        else
            cout<<"Player 2\n";
    }
    
    
    return 0;
}