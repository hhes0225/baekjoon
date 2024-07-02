#include <iostream>
#include <string>
using namespace std;

int main() {
    int input;
    int budget = 5000;
    
    while(cin>>input){

        if(input==1){
            budget-=500;
        }
        else if(input==2){
            budget-=800;
        }
        else{
            budget-=1000;    
        }
    }

    cout<<budget<<"\n";
    
    return 0;
}