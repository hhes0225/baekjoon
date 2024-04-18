#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    char op, eq;

    cin>>a>>op>>b>>eq>>c;

    if(a+b==c){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}