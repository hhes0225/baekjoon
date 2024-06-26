#include <iostream>
#include <string>
using namespace std;

int main() {
    string mbti;
    string reverseMbti="";

    cin>>mbti;

    if(mbti[0]=='E'){
        reverseMbti+="I";
    }
    else{
        reverseMbti+="E";
    }

    if(mbti[1]=='N'){
        reverseMbti+="S";
    }
    else{
        reverseMbti+="N";
    }

    if(mbti[2]=='T'){
        reverseMbti+="F";
    }
    else{
        reverseMbti+="T";
    }

    if(mbti[3]=='J'){
        reverseMbti+="P";
    }
    else{
        reverseMbti+="J";
    }

    cout<<reverseMbti<<endl;
    
    return 0;
}