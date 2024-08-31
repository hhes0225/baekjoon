#include <iostream>
using namespace std;

int main() {
    int stones;

    cin>>stones;

    if(stones%2==0){
        cout<<"SK\n";    
    }
    else{
        cout<<"CY\n";
    }

    
    return 0;
}