#include <bits/stdc++.h>
using namespace std;
const int MAX = 400'000;
const int OFFSET = 200'000;

int n;
vector<pair<int, char>> command;
vector<int> tiles;
vector<int> bVisited;
vector<int> wVisited;

int black=0;
int white=0;
int gray=0;

int main() {
    cin >> n;
    command.resize(n);

    tiles.assign(MAX, 0);
    bVisited.assign(MAX, 0); 
    wVisited.assign(MAX, 0);


    for (auto &c:command) {
        cin >> c.first>>c.second;
    }
    

    int cur=OFFSET;

    for(auto c:command){
        auto [amt, dir]=c;

        if(dir=='R'){//검은색으로
            for(int i=0;i<amt;i++){
                tiles[cur]=1;
                bVisited[cur]++;
                
                if(i!=amt-1) cur++;
            }
        }
        else{//흰색으로
            for(int i=0;i<amt;i++){
                tiles[cur]=-1;
                wVisited[cur]++;

                if(i!=amt-1) cur--;
            }
        }

        // for(int i=0;i<MAX;i++){
        //     if(bVisited[i]==0&&wVisited[i]==0) continue;

        //     cout<<i-OFFSET<<": "<<bVisited[i]<<", "<<wVisited[i]<<", "<<tiles[i]<<"\n";
        // }
        // cout<<"==================\n";
    }

    

    for(int i=0;i<MAX;i++){
        if(bVisited[i]==0&&wVisited[i]==0) continue;

        if(bVisited[i]>=2 && wVisited[i]>=2){
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