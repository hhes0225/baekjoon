#include <iostream>
#include <vector>
using namespace std;

int maxScore[9]={100,100,200,200,300,300,400,400,500};
int drawLimit=100;

int main() {
    int total=0;
    bool isHacker=false;
    
    for(int i=0;i<9;i++){
        int input;
        cin>>input;
        
        if(input>maxScore[i]){
            cout<<"hacker\n";
            isHacker=true;
            break;
        }

        total+=input;
    }

    if(!isHacker){
        if(total>=drawLimit){
            cout<<"draw\n";
        }
        else{
            cout<<"none\n";
        }
    }
    
    return 0;
}