#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin>>input;
    
    int DKSH=0;

    for(int i=0;i<input.size();i++){
        string tmp;
        tmp=input.substr(i, 4);
    
        if(tmp=="DKSH"){
            DKSH++;
        }

        //cout<<tmp<<endl;
    }

    cout<<DKSH<<endl;
    

    
    return 0;
}