#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    while(1){
        string input;
        getline(cin, input);

        if(input=="*"){
            break;
        }

        vector<int> alphabets;
        alphabets.resize((int)'z'-(int)'a'+1);
        bool isPangram=true;

        for(int i=0;i<input.size();i++){
            if(input[i]==' '){
                continue;
            }
            alphabets[input[i]-(int)'a']++;
        }

        for(int i=0;i<alphabets.size();i++){
            if(alphabets[i]==0){
                isPangram=false;
            }
        }

        if(isPangram){
            cout<<"Y\n";
        }
        else{
            cout<<"N\n";
        }
    }
    
    return 0;
}