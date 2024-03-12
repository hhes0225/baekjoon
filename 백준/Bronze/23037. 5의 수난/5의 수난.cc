#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string input;
    int sum=0;
    
    cin>>input;

    for(int i=0;i<input.size();i++){
        sum+=pow(input[i]-'0', 5);
    }    

    cout<<sum<<"\n";

    return 0;
}