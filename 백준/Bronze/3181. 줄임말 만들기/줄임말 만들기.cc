#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string sub="";
    int gap = (int)'A'-(int)'a';

    //cout<<(int)'a'<<" "<<(int)'A'<<endl;
    
    getline(cin, input);

    sub+=(input[0]+gap);
    
    for(int i=1;i<input.size();i++){
        if(input[i]==' '){
            //cout<<input.substr(i+1, 2)<<endl;
            if(input.substr(i+1, 2)== "i "|| input.substr(i+1, 2) == "a "){
                continue;
            }
            else if(input.substr(i+1, 3) == "pa "|| input.substr(i+1, 3) == "te "
                || input.substr(i+1, 3) == "ni " || input.substr(i+1, 3) == "no "){
                continue;    
            }
            else if(input.substr(i+1, 4) == "ali "|| input.substr(i+1, 4) == "ili "){
                continue;
            }
            else if(input.substr(i+1, 5) == "niti "|| input.substr(i+1, 5) == "nego "){
                continue;
            }
            
            sub+=(input[i+1]+gap);
        }
    }

    cout<<sub<<endl;
    
    return 0;
}