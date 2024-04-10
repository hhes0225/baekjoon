#include <iostream>
using namespace std;


int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int initial, second;
        cin>>initial>>second;

        int result;
        result=initial+(second/4)-(second/7);

        cout<<result<<"\n";
    }
    
    return 0;
}