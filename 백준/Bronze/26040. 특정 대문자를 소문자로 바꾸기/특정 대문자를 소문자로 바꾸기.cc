#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin>>input;

    char change;

    int diff = (int)'a'-(int)'A';
    //cout<<(int)'a'<<" "<<(int)'A'<<endl;
    
    while(cin>>change){
        for(int i=0;i<input.size();i++){
            if(input[i]==change){
                input[i]=(int)input[i] + diff;
            }
        }
    }

    cout<<input<<"\n";
    
    return 0;
}