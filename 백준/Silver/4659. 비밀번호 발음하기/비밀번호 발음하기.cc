#include <iostream>
#include <vector>
using namespace std;

string vowel="aeiou";


int main() {
    string pw;

    while(1){
        cin>>pw;
        bool includeVowel=false;
        bool isDup=false;
        bool isContVoCon=false;
        

        if(pw=="end"){
            break;
        }

        //1. 모음 하나 반드시 포함하기
        for(int i=0;i<pw.size();i++){
            if(vowel.find(pw[i])!=string::npos){
                includeVowel=true;
            }
        }

        if(!includeVowel){
            cout<<"<"<<pw<<"> is not acceptable.\n";
            continue;
        }

        //2. 같은 글자가 연속적으로 두번 오면 안됨
        for(int i=1;i<pw.size();i++){
            if(pw[i-1]==pw[i] && pw[i]!='e' && pw[i]!='o'){
                isDup=true;
            }
        }

        if(isDup){
            cout<<"<"<<pw<<"> is not acceptable.\n";
            continue;
        }

        //3. 모음 3개 자음 3개 연속이면 안됨
        for(int i=2;i<pw.size();i++){
            if(vowel.find(pw[i-2])!=string::npos&&vowel.find(pw[i-1])!=string::npos&&vowel.find(pw[i])!=string::npos){
                isContVoCon=true;
            }

            if(vowel.find(pw[i-2])==string::npos&&vowel.find(pw[i-1])==string::npos&&vowel.find(pw[i])==string::npos){
                isContVoCon=true;
            }
            
        }

        if(isContVoCon){
            cout<<"<"<<pw<<"> is not acceptable.\n";
            continue;
        }

        cout<<"<"<<pw<<"> is acceptable.\n";
        
        
    }
    return 0;
}