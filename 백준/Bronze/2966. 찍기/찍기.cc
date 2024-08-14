#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second>b.second;
}

int main() {
    int problems;
    string sol;
    vector<pair<string, int>> list;

    string sang = "ABC";
    string chang="BABC";
    string hyun="CCAABB";

    int sangRight=0;
    int changRight=0;
    int hyunRight=0;
    
    cin>>problems;
    cin>>sol;

    for(int i=0;i<sol.size();i++){
        if(sang[i%sang.size()]==sol[i]){
            sangRight++;
        }
        
        if(chang[i%chang.size()]==sol[i]){
            changRight++;
        }
        
        if(hyun[i%hyun.size()]==sol[i]){
            hyunRight++;
        }
    }

    //cout<<sangRight<<" "<<changRight<<" "<<hyunRight<<"\n";

    list.push_back({"Adrian", sangRight});
    list.push_back({"Bruno", changRight});
    list.push_back({"Goran", hyunRight});

    sort(list.begin(), list.end(), compare);

    cout<<list[0].second<<"\n";
    cout<<list[0].first<<"\n";
    
    for(int i=1;i<list.size();i++){
        if(list[0].second==list[i].second){
            cout<<list[i].first<<"\n";
        }
    }
    
    
    return 0;
}