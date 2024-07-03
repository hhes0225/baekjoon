#include <iostream>
#include <string>
using namespace std;

int main() {
    //cout<<(int)'A'<<" "<<(int)'a'<<endl;
    
    while(1){
        string input;

        int alphabet[26]={0, };
        int variety=0;
        
        getline(cin, input);

        if(input=="#"){
            break;
        }

        for(int i=0;i<input.size();i++){
            if((int)input[i]>=(int)'A' && (int)input[i]<=(int)'Z'){
                //cout<<input[i]<<" 대문자\n";

                if(alphabet[(int)input[i]-(int)'A']==0){
                    alphabet[(int)input[i]-(int)'A']++;
                }
            }
            else if((int)input[i]>=(int)'a' && (int)input[i]<=(int)'z'){
                //cout<<input[i]<<" 소문자\n";

                if(alphabet[(int)input[i]-(int)'a']==0){
                    alphabet[(int)input[i]-(int)'a']++;
                }
            }
        }

        for(int i=0;i<26;i++){
            variety+=alphabet[i];
        }

        cout<<variety<<"\n";
    }
    
    return 0;
}