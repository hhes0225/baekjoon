#include <iostream>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    string origin="";

    for(int i=0;i<input.size();i++){
        //cout<<i<<endl;
        origin+=input[i];
        if(input[i]=='a'||input[i]=='e'||input[i]=='i'
        ||input[i]=='o'||input[i]=='u'){
            i+=2;
        }
        
    }

    cout<<origin<<"\n";
    
    return 0;
}