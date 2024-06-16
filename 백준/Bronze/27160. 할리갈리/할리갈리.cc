#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;
    bool isBell=false;
    string fruit;
    int num;
    unordered_map<string, int> freq;

    for(int i=0;i<tCase;i++){
        cin>>fruit>>num;

        if(freq.find(fruit)!=freq.end()){
            freq[fruit]+=num;
        }
        else{
            freq.insert({fruit, num});
        }
        
    }

    for(auto it=freq.begin(); it!=freq.end(); it++){
        if(it->second==5){
            isBell=true;
        }
    }

    if(isBell){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
    return 0;
}