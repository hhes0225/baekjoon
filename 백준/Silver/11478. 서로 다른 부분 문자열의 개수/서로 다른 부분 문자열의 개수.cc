#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin>>input;

    unordered_set<string> strSet;

    for(int i=1;i<=input.size();i++){
        for(int j=0;j<input.size();j++){
            strSet.insert(input.substr(j,i));
        }
    }

    cout<<strSet.size()<<"\n";

    
    return 0;
}