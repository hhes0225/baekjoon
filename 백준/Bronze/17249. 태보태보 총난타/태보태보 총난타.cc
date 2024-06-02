#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string input;
    cin>>input;
    int i=0;

    int leftHook=0;
    int rightHook=0;
    
    while(1){
        if(input[i]=='('){
            break;
        }

        if(input[i]=='@'){
            leftHook++;
        }
        i++;
    }

    for(int j=i;j<input.size();j++){
        if(input[j]=='@'){
            rightHook++;
        }
    }

    cout<<leftHook<<" "<<rightHook<<endl;
    
    
    
    return 0;
}