#include <iostream>
using namespace std;


int main() {
    int tCase;
    int result=0;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;

        if(input%2==1){
            result++;
        }
    }

    cout<<result;
    return 0;
}