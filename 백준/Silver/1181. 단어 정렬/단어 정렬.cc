#include <bits/stdc++.h>
using namespace std;

vector<string> dictionary;


int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        dictionary.push_back(input);
    }

    sort(dictionary.begin(), dictionary.end(),
        [](string a, string b){
           if(a.size()!=b.size()) {
               return a.size()<b.size();
           }
            else{
                return a<b;
            }
    });

    //정렬 후 중복 제거 가능
    dictionary.erase(unique(dictionary.begin(), dictionary.end()), dictionary.end());

    for(auto d:dictionary){
        cout<<d<<"\n";
    }
    
    return 0;
}