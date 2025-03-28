#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<vector<int>> board;
vector<vector<char>> bStatus;
int score=0;

void printBoard(){
    for(auto i:bStatus){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
    // cout<<"------------\n";
}

void attack(int r, int c, char dir){
    int amt=board[r][c];

    // cout<<"위치: "<<r<<" "<<c<<"\n";

    if(bStatus[r][c]=='F') return;//이미 쓰러진 칸 공격. 아무 일 X
    
    if(dir=='E'){//행고정, 열만
        while(c<m && amt>0){
            if(bStatus[r][c]=='F') {
                c++; amt--;
                continue;
            }

            amt=max(amt-1, board[r][c]);

            bStatus[r][c]='F';//쓰러뜨림
            c++;
            score++;
        }
        
    }
    else if(dir=='W'){//행고정, 열만
        while(c>=0 && amt>0){
            if(bStatus[r][c]=='F') {
                c--; amt--;
                continue;
            }

            amt=max(amt-1, board[r][c]-1);
            
            bStatus[r][c]='F';//쓰러뜨림
            c--;score++;
        }
    }
    else if(dir=='S'){//열고정, 행만
        while(r<n && amt>0){
            if(bStatus[r][c]=='F') {
                r++; amt--;
                continue;
            }
            
            amt=max(amt-1, board[r][c]-1);
            
            bStatus[r][c]='F';//쓰러뜨림
            r++;score++;
        }
    }
    else{//dir=='N' | 열고정, 행만
        while(r>=0 && amt>0){
            // cout<<r<<" "<<c<<" "<<amt<<" "<<board[r][c]<<"\n";
            if(bStatus[r][c]=='F'){//이미 쓰러져있다면
                r--;amt--;
                continue;
            }

            amt=max(amt-1, board[r][c]-1);
            
            bStatus[r][c]='F';//쓰러뜨림
            score++;//쓰러뜨리지 않은 칸을 쓰러뜨린거라면
            r--;
        }
    }
}

void defence(int r, int c){
    bStatus[r][c]='S';
}

void deathGame(int n, int m, int r){

    for(int i=0;i<r;i++){
        int r, c;
        char dir;
        //공격
        cin>>r>>c>>dir;
        attack(r-1, c-1, dir);

        //수비
        cin>>r>>c;
        defence(r-1,c-1);
        // printBoard();
    }
}

int main() {

    cin>>n>>m>>r;

    board.resize(n, vector<int>(m));
    bStatus.assign(n, vector<char>(m, 'S'));

    for(auto&i:board){
        for(auto&j:i) cin>>j;
    }

    
    deathGame(n,m,r);

    cout<<score<<"\n";
    
    printBoard();
    
    
    return 0;
}