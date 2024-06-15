#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int input;
    cin>>input;

    for(int i=0;i<input;i++){
        cout<<1;
    }

    for(int i=0;i<input-1;i++){
        cout<<0;
    }
    
    return 0;
}