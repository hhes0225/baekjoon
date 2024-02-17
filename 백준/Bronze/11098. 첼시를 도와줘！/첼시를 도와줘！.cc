#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first>b.first;
}

int main(void){
    int tCase;
    int playerNum;
    

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        cin>>playerNum;
        vector<pair<int, string>> players;
        players.resize(playerNum);
        
        for(int j=0;j<playerNum;j++){
            cin>>players[j].first>>players[j].second;
        }
        
        sort(players.begin(), players.end(), compare);
        cout<<players[0].second<<endl;
    }
    
    return 0;
}