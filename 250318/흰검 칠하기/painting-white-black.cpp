#include <bits/stdc++.h>
using namespace std;
const int MAX = 400'000;
const int OFFSET = 200'000;

int n;
vector<pair<int, char>> command;
vector<int> tiles;
vector<int> visited;
int black=0;
int white=0;
int gray=0;

int main() {
    cin >> n;
    command.resize(n);

    tiles.assign(MAX, 0);
    visited.assign(MAX, 0); 


    for (auto &c:command) {
        cin >> c.first>>c.second;
    }
    

    int cur=OFFSET;

    for(auto c:command){
        auto [amt, dir]=c;

        if(dir=='R'){//검은색으로
            for(int i=0;i<amt;i++){
                if(visited[cur]<4) tiles[cur]=1;
                visited[cur]++;
                
                if(i!=amt-1) cur++;
            }
        }
        else{//흰색으로
            for(int i=0;i<amt;i++){
                if(visited[cur]<4) tiles[cur]=-1;
                visited[cur]++;

                if(i!=amt-1) cur--;
            }
        }
    }

    // for(int i=0;i<MAX;i++){
    //     if(visited[i]==0) continue;

    //     cout<<i-OFFSET<<": "<<visited[i]<<", "<<tiles[i]<<"\n";
    // }

    for(int i=0;i<MAX;i++){
        if(visited[i]==0) continue;

        if(visited[i]>=4){
            gray++;
            continue;
        }

        if(tiles[i]>0){
            black++;
        }
        else{
            white++;
        }
    }
    
    cout<<white<<" "<<black<<" "<<gray<<"\n";

    return 0;
}