#include <iostream>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int probs;
        cin>>probs;

        for(int j=0;j<probs;j++){
            int a, b;
            cin>>a>>b;
    
            cout<<a+b<<" "<<a*b<<"\n";
        }
        
    }
    
    return 0;
}