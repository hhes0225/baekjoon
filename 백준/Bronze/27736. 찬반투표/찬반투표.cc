#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tCase;
    int result=0;
    int vote=0;

    cin>>tCase;
    
    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;

        if(input!=0){
            vote++;
        }

        result+=input;
    }

    if(vote<=tCase/2){
        cout<<"INVALID\n";
    }
    else if(result>0){
        cout<<"APPROVED\n";
    }
    else{
        cout<<"REJECTED\n";
    }
    
    return 0;
}