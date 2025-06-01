#include <bits/stdc++.h>
using namespace std;

vector<char> chars;
vector<char> pw;
vector<bool> visited;

set<char> v;

bool isPossiblePw(){
    int vowel=0, consonant=0;

    for(auto p:pw){
        if(v.find(p)!=v.end()){
            vowel++;
        }
        else consonant++;
    }

    // cout<<vowel<<" "<<consonant<<"\n";

    if(vowel>=1 && consonant>=2) return true;
    else return false;
}

void backtracking(int n, int l){
    if(l==0){
        if(isPossiblePw()){
            for(auto p:pw) cout<<p;
            cout<<"\n";
        }

        return;
    }

    for(int i=n;i<chars.size();i++){
        if(!visited[i]){
            visited[i]=true;
            pw.push_back(chars[i]);

            backtracking(i+1, l-1);
            
            //원복
            visited[i]=false;
            pw.pop_back();
        }
    }
}

int main() {
    v.insert('a');v.insert('e');v.insert('i');v.insert('o');v.insert('u');
    
    int l, c;
    cin>>l>>c;

    chars.resize(c);
    visited.assign(c, false);

    for(auto &ch:chars) cin>>ch;

    sort(chars.begin(), chars.end());

    backtracking(0, l);
    
    return 0;
}