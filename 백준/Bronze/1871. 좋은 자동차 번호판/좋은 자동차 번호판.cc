#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string input;
        cin>>input;
        string tmp;
        string engTmp;
        int eng=0;
        int num;
        
        for(int j=0;j<input.size();j++){
            if(input[j]=='-'){
                engTmp=tmp;
                tmp="";
            }
            else if(j==input.size()-1){
                tmp+=input[j];
                num=stoi(tmp);
            }
            else{
                tmp+=input[j];
            }
        }

        for(int j=0;j<engTmp.size();j++){
            //cout<<"곱셈: "<<((int)engTmp[j]-(int)'A')<<endl;
            //cout<<"제곱: "<<pow(26, engTmp.size()-j)<<endl;
            //cout<<"제곱수: "<<engTmp.size()-j<<endl;
            eng+=(((int)engTmp[j]-(int)'A')*pow(26, engTmp.size()-j-1));
        }

        if(abs(eng-num)<=100){
            cout<<"nice\n";
        }
        else{
            cout<<"not nice\n";
        }
    }
    return 0;
}