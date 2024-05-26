#include <iostream>
#include <vector>
using namespace std;


int main() {
    string input;
    cin>>input;

    vector<bool> cup;
    cup.resize(3);
    cup[0]=true;
    
    for(int i=0;i<input.size();i++){
        if(input[i]=='A'){
            if(cup[0] || cup[1]){
                cup[0] = !(cup[0]);
                cup[1] = !(cup[1]);
            }
        }
        else if(input[i]=='B'){
            if(cup[2] || cup[1]){
                cup[2] = !(cup[2]);
                cup[1] = !(cup[1]);
            }
        }
        else if(input[i]=='C'){
            if(cup[2] || cup[0]){
                cup[2] = !(cup[2]);
                cup[0] = !(cup[0]);
            }
        }
    }

    for(int i=0;i<cup.size();i++){
        if(cup[i]){
            cout<<i+1<<"\n";
        }
    }
    
    return 0;
}