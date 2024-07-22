#include <iostream>
using namespace std;
int main() {
    int aAtk, bAtk;
    int aHp, bHp;
    int aKill, bKill;

    cin>>aAtk>>aHp;
    cin>>bAtk>>bHp;

    while(1){
        if(aHp<=0||bHp<=0){
            if(aHp<=0 && bHp<=0){
                cout<<"DRAW\n";
            }
            else if(aHp<=0){
                cout<<"PLAYER B\n";
            }
            else if(bHp<=0){
                cout<<"PLAYER A\n";
            }
            break;
        }
        
        bHp -= aAtk;
        aHp -= bAtk;
    }

    

    //cout<<aKill<<" "<<bKill<<endl;
    /*
    if(aKill<bKill){
        cout<<"PLAYER A\n";
    }
    else if(aKill>bKill){
        cout<<"PLAYER B\n";
    }
    else{
        cout<<"DRAW\n";
    }
    */
    
    return 0;
}