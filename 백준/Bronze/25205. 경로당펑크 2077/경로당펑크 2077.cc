#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    string input;
    
    cin>>length>>input;

    char lastWord = input[input.size()-1];

    //ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅣㅛㅜㅠㅡ
    if(lastWord=='k'||lastWord=='o'||lastWord=='i'||lastWord=='O'||
    lastWord=='j'||lastWord=='p'||lastWord=='u'||lastWord=='P'||
    lastWord=='h'||lastWord=='l'||lastWord=='y'||lastWord=='n'||
    lastWord=='b'||lastWord=='m'){
        cout<<0<<"\n";
    }
    else{
        cout<<1<<"\n";
    }

    
    return 0;
}