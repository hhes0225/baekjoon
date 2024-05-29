#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string keyword;

    cin>>input>>keyword;

    string rmvNum="";

    for(int i=0;i<input.size();i++){
        if(input[i]>='0' && input[i]<='9'){
            continue;
        }

        rmvNum+=input[i];
    }

    if(rmvNum.find(keyword) != string::npos){
        cout<<1<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
    
    return 0;
}