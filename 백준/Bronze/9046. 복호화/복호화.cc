#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

int main() {
    int tCase;
    
    cin>>tCase;
    cin.ignore();

    for(int i=0;i<tCase;i++){
        string input;
        int alphabet[26]={};
        pair<char, int> maxUsed;
        maxUsed.second=-1;
        
        getline(cin, input);

        for(int j=0;j<input.size();j++){
            if(input[j]>='a' && input[j]<='z'){
                alphabet[(int)input[j]-(int)'a']++;
            }
        }
    
        bool isMultipleMax = false;
        for(int j=0;j<26;j++){
            if(maxUsed.second < alphabet[j]){
                maxUsed.second = alphabet[j];
                maxUsed.first = (char)(j+(int)'a');
                isMultipleMax = false;
            }
            else if(maxUsed.second == alphabet[j]){
                isMultipleMax = true;
            }
        }
    
        if(isMultipleMax){
            cout<<"?"<<endl;
        }
        else{
            cout<<maxUsed.first<<"\n";
        }
    }
    
    
    return 0;
}
