#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int num[10] = {0, };
    bool related=true;
    
    cin>>input;

    for(int i=0;i<input.size();i++){
        int idx = (int)input[i]-(int)'0';

        num[idx]++;
    }

    for(int i=0;i<10;i++){
        if(i>2 && i!=8){
            if(num[i]!=0){
                related=false;
            }
        }
    }

    if(related){
        //관련있는
        if(num[0]>0 && num[1]>0 && num[2]>0 && num[8]>0){
            //밀접
            if(num[0]==num[1] && num[0]==num[2] && num[0]==num[8]){
                //묶여있는
                cout<<8<<"\n";
            }
            else{
                cout<<2<<"\n";
            }
        }
        else{
            cout<<1<<"\n";
        }
    }
    else{
        //관련없는
        cout<<0<<"\n";
    }
    
    return 0;
}