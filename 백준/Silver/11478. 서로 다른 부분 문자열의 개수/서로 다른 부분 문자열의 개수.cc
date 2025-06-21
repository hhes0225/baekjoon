#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin>>input;

    unordered_set<string> strSet;

    for(int i=1;i<=input.size();i++){
        for(int j=0;j<input.size();j++){
            string tmp=input.substr(j,i);

            if(tmp.size()==i)
                strSet.insert(tmp);
        }
    }


    cout<<strSet.size()<<"\n";

    
    return 0;
}