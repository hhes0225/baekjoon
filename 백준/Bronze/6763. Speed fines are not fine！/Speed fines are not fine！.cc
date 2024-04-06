#include <iostream>
using namespace std;

int main(void){
    int limit;
    int recorded;

    cin>>limit>>recorded;

    if(limit>=recorded){
        cout<<"Congratulations, you are within the speed limit!"<<endl;
    }
    else{
        int diff=recorded-limit;

        if(diff>=1 && diff<=20){
            cout<<"You are speeding and your fine is $100."<<endl;
        }
        else if(diff>=21 && diff<=30){
            cout<<"You are speeding and your fine is $270."<<endl;
        }
        else{
            cout<<"You are speeding and your fine is $500."<<endl;
        }
        
    }

    return 0;
}