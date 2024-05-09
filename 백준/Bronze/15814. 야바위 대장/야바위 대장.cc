#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input;
    int tCase;

    cin>>input>>tCase;

    for(int i=0;i<tCase;i++){
        int a,b;
        cin>>a>>b;

        char tmp = input[a];
        input[a]=input[b];
        input[b]=tmp;
    }

    cout<<input<<"\n";
    
    return 0;
}