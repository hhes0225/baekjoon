#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input;

    getline(cin, input);

    if(input.find("D2")!=string::npos){
        cout<<"D2\n";
    }
    else if(input.find("d2")!=string::npos){
        cout<<"D2\n";
    }
    else{
        cout<<"unrated\n";
    }
    
    return 0;
}