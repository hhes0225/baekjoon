#include <iostream>
#include <string>
using namespace std;

int main() {
    int magNum;
    string magnet;
    bool isConnect=true;

    cin>>magNum;
    cin>>magnet;

    for(int i=1;i<magnet.size();i++){
        if(magnet[i]==magnet[i-1]){
            isConnect=false;
            break;
        }
    }

    if(isConnect){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    
    return 0;
}