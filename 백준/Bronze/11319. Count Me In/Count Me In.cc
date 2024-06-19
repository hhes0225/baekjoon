#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tCase;

    cin>>tCase;
    cin.ignore();
    
    for(int i=0;i<tCase;i++){
        string input;
        int consonant=0, vowel=0;
        
        getline(cin, input);

        for(int j=0;j<input.size();j++){
            if(input[j]=='A'||input[j]=='a'){
                vowel++;
            }
            else if(input[j]=='E'||input[j]=='e'){
                vowel++;
            }
            else if(input[j]=='I'||input[j]=='i'){
                vowel++;
            }
            else if(input[j]=='O'||input[j]=='o'){
                vowel++;
            }
            else if(input[j]=='U'||input[j]=='u'){
                vowel++;
            }
            else if(input[j]==' '){
                continue;
            }
            else{
                consonant++;
            }
        }

        cout<<consonant<<" "<<vowel<<"\n";
    }
    
    return 0;
}