#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input;

    while(1){
        getline(cin, input);

        if(input=="***"){
            break;
        }

        reverse(input.begin(), input.end());
        cout<<input<<"\n";
    }
    
    return 0;
}