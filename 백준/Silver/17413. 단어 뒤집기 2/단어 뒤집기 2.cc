#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string input;
    vector<string> reverseStr;
    bool isReverse=true;
    string tmp;
    
    getline(cin, input);

    //cout<<input;

    for(int i=0;i<input.size();i++){
        if(input[i]=='<'){
            if(tmp!=""){
                reverse(tmp.begin(), tmp.end());
                reverseStr.push_back(tmp);
            }
            tmp="<";
            isReverse=false;
            
        }
        else if(input[i]=='>'){
            tmp+='>';
            reverseStr.push_back(tmp);
            tmp="";
            isReverse=true;
        }
        else if(input[i]==' '){
            if(isReverse){// true 라면 문자열 뒤집기
                reverse(tmp.begin(), tmp.end());
                reverseStr.push_back(tmp);
                reverseStr.push_back(" ");
                tmp="";
            }
            else{
                reverseStr.push_back(tmp);
                reverseStr.push_back(" ");
                tmp=""; 
            }
        }
        else{
            tmp+=input[i];
        }
    }

    if(tmp!=""){
        reverse(tmp.begin(), tmp.end());
        reverseStr.push_back(tmp);
    }

    for(int i=0;i<reverseStr.size();i++){
        cout<<reverseStr[i];
    }

    cout<<"\n";
    return 0;
}