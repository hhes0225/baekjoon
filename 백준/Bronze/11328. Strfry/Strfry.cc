#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string a, b;

        cin>>a>>b;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a==b){
            cout<<"Possible"<<endl;
        }
        else{
            cout<<"Impossible"<<endl;
        }
    }

    return 0;
}