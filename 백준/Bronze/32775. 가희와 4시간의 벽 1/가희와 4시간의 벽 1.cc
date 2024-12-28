#include <iostream>
using namespace std;

int main() {
    int sab, fab;
    cin>>sab>>fab;

    if(sab<=fab){
        cout<<"high speed rail\n";
    }
    else{
        cout<<"flight\n";
    }
    return 0;
}