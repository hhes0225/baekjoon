#include <iostream>

using namespace std;

char binary[9];

int main() {
    string bin="";
    cin>>bin;

    int ans=0;

    for(int i=0;i<bin.size();i++){
        ans=(ans*2)+(bin[i]-'0');
    }

    cout<<ans<<"\n";

    return 0;
}