#include <iostream>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string a, b;
        int hammingDistance=0;
        cin>>a>>b;

        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j]){
                hammingDistance++;
            }
        }

        cout<<"Hamming distance is "<<hammingDistance<<".\n";
    }
    
    return 0;
}