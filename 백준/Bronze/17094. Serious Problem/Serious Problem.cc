#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int two=0, e=0;
    int len;

    cin>>len;

    cin>>input;

    for(int i=0;i<len;i++){
        if(input[i]=='2'){
            two++;
        }
        if(input[i]=='e'){
            e++;
        }
    }

    if(two>e){
        cout<<"2\n";
    }
    else if(two<e){
        cout<<"e\n";
    }
    else{
        cout<<"yee\n";
    }

    
    return 0;
}