#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int strLength;
    string input;
    int bonus=0;
    int score=0;
    
    cin>>strLength;
    cin>>input;

    for(int i=0;i<strLength;i++){
        if(input[i]=='X'){
            bonus=0;
        }
        else{
            score+=i+1;
            score+=bonus;
            bonus++;
        }
    }

    cout<<score<<"\n";
    
    
    return 0;
}