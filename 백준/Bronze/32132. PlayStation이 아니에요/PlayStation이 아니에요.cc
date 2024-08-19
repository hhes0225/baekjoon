#include <iostream>
using namespace std;

int main() {
    int length;
    string input;
    
    cin>>length;
    cin>>input;

    //cout<<input.find("PS5")<<endl;
    //cout<<input.find("PS4")<<endl;
    
    while(1){
        if(input.find("PS5")==string::npos && input.find("PS4")==string::npos){
            break;
        }

        if(input.find("PS5")!=string::npos){
            input.erase(input.find("PS5")+2,1);
            //cout<<input<<endl;
        }    

        if(input.find("PS4")!=string::npos){
            input.erase(input.find("PS4")+2,1);
            //cout<<input<<endl;
        }   
    }

    cout<<input<<endl;
    
    

    
    return 0;
}