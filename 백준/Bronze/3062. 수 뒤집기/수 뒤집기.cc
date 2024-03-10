#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string input;
        string inputCpy;

        cin>>input;

        inputCpy = input;
        reverse(inputCpy.begin(), inputCpy.end());
        
        //원래 수와 뒤집은 수의 합
        string sum=to_string(stoi(input)+stoi(inputCpy));

        //cout<<sum<<"\n";
        
        bool isPal=true;

        //팰린드롬 여부 확인(sum문자열의 좌우 대칭 여부 확인)
        for(int i=0;i<sum.size();i++){
            if(sum[i]!=sum[sum.size()-1-i]){
                isPal=false;
            }
        }
        
        if(isPal){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    

    return 0;
}