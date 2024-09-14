#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tCase;
    int fall=1;
    int prev, cur;

    cin>>tCase;

    cin>>prev;
    
    for(int i=1;i<tCase;i++){
        cin>>cur;

        if(prev<=cur){
            fall++;
        }

        prev=cur;
    }

    cout<<fall<<"\n";
    
    return 0;
}