#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, string> a, pair<string, string> b){
    return a.first<b.first;
}

int main() {
    int tCase;

    while(1){
        vector<pair<string, string>> words;
        
        cin>>tCase;
        if(tCase==0){
            break;
        }

        for(int i=0;i<tCase;i++){
            string tmp;
            cin>>tmp;

            string lower=tmp;

            for(int j=0;j<lower.size();j++){
                lower[j]=tolower(lower[j]);
            }
            
            words.push_back({lower, tmp});
        }

        sort(words.begin(), words.end(), compare);

        cout<<words[0].second<<endl;
        
    }
    
    return 0;
}