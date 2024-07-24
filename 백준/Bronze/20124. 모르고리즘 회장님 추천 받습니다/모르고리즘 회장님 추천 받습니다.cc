#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    if(a.second!=b.second){
        return a.second>b.second;
    }
    else{
        return a.first<b.first;
    }
}

int main() {
    vector<pair<string, int>> vote;  
    int tCase;

    cin>>tCase;
    
    for(int i=0;i<tCase;i++){
        string name;
        int voteNum;
        cin>>name>>voteNum;

        vote.push_back({name, voteNum});
    }

    sort(vote.begin(), vote.end(), compare);

    /*for(int i=0;i<vote.size();i++){
        cout<<vote[i].first<<" "<<vote[i].second<<endl;
    }*/

    cout<<vote[0].first<<endl;
    
    
    return 0;
}