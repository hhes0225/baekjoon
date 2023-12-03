#include <iostream>

using namespace std;

int main(void){
    int chicken;
    int coke, beer;
    int drink;
    int eat;
    
    cin>>chicken>>coke>>beer;
    
    drink=coke/2+beer;
    
    if(chicken<=drink)
        eat=chicken;
    else
        eat=drink;
    
    cout<<eat<<endl;
    
    
    return 0;
}