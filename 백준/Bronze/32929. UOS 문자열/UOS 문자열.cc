#include <iostream>
using namespace std;
int main() {
    int len;
    cin>>len;

    if(len%3==1){
        cout<<"U\n";
    }
    else if(len%3==2){
        cout<<"O\n";
    }
    else{
        cout<<"S\n";
    }
    return 0;
}