#include <bits/stdc++.h>
using namespace std;

/*
    change의 가장 뒤 글자(back)가 A면, A 떼기만 가능
    change의 가장 뒤 글자(back)가 B면, B 떼고 문자열 뒤집기만 가능
    original의 글자수가 될 때까지 돌고, 
    change==original이면 참, 아니면 거짓
*/
int main() {
    string original, change;
    bool canMake;
    
    cin>>original>>change;

    while(change.size()!=original.size()){
        if(change.back()=='A'){
            change=change.substr(0,change.size()-1);
            // cout<<change<<"\n";
        }
        else{
            change=change.substr(0,change.size()-1);
            reverse(change.begin(), change.end());
            // cout<<change<<"\n";
        }
    }

    if(change==original) canMake=true;
    else canMake=false;
    
    cout<<canMake<<"\n";
    
    return 0;
}