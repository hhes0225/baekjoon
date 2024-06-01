#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void CheckPel(string input){
    bool isPel = true;

    for(int i=0;i<input.size()/2;i++){
        if(input[i]!=input[input.size()-i-1]){
            isPel=false;
            break;
        }
    }

    if(isPel){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

int main() {
    int tCase;
    cin>>tCase;

    cin.ignore();
    
    for(int i=0;i<tCase;i++){
        string input;
        getline(cin, input);

        for(int j=0;j<input.size();j++){
            input[j]=tolower(input[j]);
        }

        CheckPel(input);
    }
    
    
    return 0;
}