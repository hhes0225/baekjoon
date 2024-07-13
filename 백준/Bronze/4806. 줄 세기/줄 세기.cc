#include <iostream>
#include <string>
using namespace std;



int main() {
    string input;
    int line=0;
    
    while(getline(cin, input)){
        line++;
    }

    cout<<line<<"\n";

    return 0;
}