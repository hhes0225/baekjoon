#include <iostream>
#include <string>
using namespace std;

int getCount(char c){
    int ascii = (int)c;
    int result = 0;

    //cout<<ascii<<" ";
    //cout<<to_string(ascii).size()<<" ";
    int strSize = to_string(ascii).size();
    for(int i=0;i<strSize;i++){
        //cout<<ascii%10<<" ";
        result += (ascii%10);
        ascii/=10;
    }

    return result;
}

int main() {
    string input;
    cin>>input;

    for(int i=0;i<input.size();i++){
        //cout<<getCount(input[i])<<"\n";
        int count = getCount(input[i]);
        
        for(int j=0;j<count;j++){
            cout<<input[i];
        }

        cout<<"\n";
    }
    
    return 0;
}