#include <iostream>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;
    cin.ignore();

    for(int i=0;i<tCase;i++){
        string input;
        int g=0, b=0;
        
        getline(cin, input);

        for(int j=0;j<input.size();j++){
            if(input[j]=='g' || input[j]=='G'){
                g++;
            }
            else if(input[j]=='b'||input[j]=='B'){
                b++;
            }
        }

        if(g>b){
            cout<<input<<" is GOOD\n";
        }
        else if(g<b){
            cout<<input<<" is A BADDY\n";
        }
        else{
            cout<<input<<" is NEUTRAL\n";
        }
    }
    
    return 0;
}