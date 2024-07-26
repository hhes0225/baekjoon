#include <iostream>
#include <string>
using namespace std;


int main() {
    int len;
    string input;
    int alphabet[26]={};

    cin>>len;
    cin.ignore();
    getline(cin, input);

    for(int i=0;i<len;i++){
        if(input[i]>='a' && input[i]<='z'){
            alphabet[(int)input[i]-(int)'a']++;
        }
    }

    int maxUsed=-1;
    for(int i=0;i<26;i++){
        maxUsed=max(maxUsed, alphabet[i]);
    }

    cout<<maxUsed;
    
    return 0;
}