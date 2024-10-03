#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b;

    if(a==b){
        c=a;
    }
    else{
        if(a>b){
            c=a;
        }
        else{
            c=b;
        }
    }

    cout<<c<<"\n";
    return 0;
}