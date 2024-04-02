#include <iostream>
using namespace std;

int main(void){
    long long int input;
    cin>>input;

    long long int fact=1;
    
    for(int i=1;i<=input;i++){

        fact*=i;
    }
    //cout<<fact<<"\n";

    long long int week;
    week=fact/60/60/24/7;
    //분-60초/시-60분/하루-24시간/일주일-7일

    cout<<week<<"\n";
    
    return 0;
}