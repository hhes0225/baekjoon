#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<char>> status;
int n, m, r;
map<char, pair<int, int>> direction={
    {'E', {0,1}},
    {'W', {0,-1}},
    {'S', {1,0}},
    {'N', {-1,0}}
};
int score=0;

void print(){
    for(auto i:status){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }

    cout<<"\n";
}

void attack(int r, int c, char dir){
    queue<pair<int, int>> domino;

    int dr=direction[dir].first;
    int dc=direction[dir].second;
    
    domino.push({r, c});//처음에 넘어뜨리는 양
        
    while(!domino.empty()){
        auto [r,c]=domino.front();
        domino.pop();
        int knock=board[r][c];

        for(int i=0;i<knock;i++){
            int nextR=r+dr*i;
            int nextC=c+dc*i;

            if(nextR<0||nextR>=n||nextC<0||nextC>=m) break;
            
            if(status[nextR][nextC]=='S'){
                score++;
                status[nextR][nextC]='F';
                domino.push({nextR, nextC});
            }
        }
    }
}

void defence(int r, int c){
    status[r][c]='S';
}

int main() {
    
    cin>>n>>m>>r;

    board.resize(n, vector<int>(m));
    status.assign(n, vector<char>(m, 'S'));

    for(auto &i:board){
        for(auto &j:i) cin>>j;
    }

    for(int i=0;i<r;i++){
        //공격
        int x, y;
        char d;
        cin>>x>>y>>d;
        attack(x-1,y-1,d);
        // print();

        //수비
        cin>>x>>y;
        defence(x-1,y-1);
        // print();
        
        // cout<<"================\n";
    }

    cout<<score<<"\n";
    print();
    
    return 0;
}