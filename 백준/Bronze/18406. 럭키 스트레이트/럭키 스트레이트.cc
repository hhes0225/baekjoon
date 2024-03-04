#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string left;
    string right;
    int leftSum=0, rightSum=0;

    cin>>input;

    for(int i=0;i<input.size()/2;i++){
        left+=input[i];
        right+=input[input.size()-1-i];
    }

    for(int i=0;i<input.size()/2;i++){
        leftSum+=((int)input[i]-(int)'0');
        rightSum+=((int)input[input.size()-1-i]-(int)'0');
    }

    //cout<<leftSum<<" "<<rightSum<<endl;

    if(leftSum==rightSum){
        cout<<"LUCKY\n";
    }
    else{
        cout<<"READY\n";
    }

    return 0;
}