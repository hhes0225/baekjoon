#include <iostream>
using namespace std;

int main() {
    int input;
    int positive=0;

    while(cin>>input){
        if(input>0){
            positive++;
        }
    }

    cout<<positive<<endl;
    
    return 0;
}