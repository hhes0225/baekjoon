#include <bits/stdc++.h>
using namespace std;

const int MAX=400'000;
const int OFFSET=200'000;

int n;
vector<pair<int, char>> command;
vector<int> tiles;
const int BLACK=1;
const int WHITE=-1;
int bTiles=0;
int wTiles=0;

int main() {
    cin >> n;
    command.resize(n);
    tiles.assign(MAX, 0);

    for (auto &c:command) {
        cin>>c.first>>c.second;
    }

    int cur=OFFSET;

    for(auto c:command){
        auto[amt, dir]=c;

        if(dir=='R'){//검은색
            for(int i=0;i<amt; i++){
                tiles[cur]=BLACK;
                
                if(i!=amt-1) cur++;
            }
        }
        else{//왼쪽, 흰색
            for(int i=0;i<amt;i++){
                tiles[cur]=WHITE;
                if(i!=amt-1) cur--;
            }
        }
    }

    for(auto t:tiles){
        if(t==0) continue;

        if(t==BLACK) bTiles++;
        else wTiles++; 
    }

    cout<<wTiles<<" "<<bTiles<<"\n";

    return 0;
}