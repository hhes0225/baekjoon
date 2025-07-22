#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char type;
    cin>>n>>type;

    int ans;

    unordered_set<string> players;

    for(int i=0;i<n;i++){
        string tmp;cin>>tmp;
        players.insert(tmp);
    }

    if(type=='Y'){
        ans=players.size();
    }
    else if(type=='F'){
        ans=players.size()/2;
    }
    else{
        ans=players.size()/3;
    }

    cout<<ans<<"\n";
    return 0;
}