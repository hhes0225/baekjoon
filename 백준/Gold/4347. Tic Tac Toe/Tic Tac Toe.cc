#include <bits/stdc++.h>
using namespace std;

//x가 먼저 시작
//x>=o 이면서, x>o인 경우 숫자는 1 차이나야 함
//xxx ooo 둘 중 한번이라도  나오면 게임 끝남
//->xxx, ooo 통틀어서 총 횟수는 1이어야 


vector<vector<char>> grid;

void printGrid(){
    for(auto i:grid){
        for(auto j:i) cout<<j;
        cout<<"\n";
    }
    cout<<"\n";
}

pair<int, int> checkVictory(){
    int xwin=0;
    int owin=0;
    

    //수평
    for(int i=0;i<3;i++){
        if(grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]
            &&grid[i][0]=='X')
            xwin++;
        if(grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]
            &&grid[i][0]=='O')
            owin++;
    }

    //수직
    for(int i=0;i<3;i++){
        if(grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]
            &&grid[0][i]=='X')
            xwin++;
        if(grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]
            &&grid[0][i]=='O')
            owin++;
    }

    //대각선
    if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]){
        if(grid[0][0]=='X')
            xwin++;
        else owin++;
    }
    
    if(grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0]){
        if(grid[0][2]=='X'){
            xwin++;
        }
        else owin++;
    }

    return {xwin, owin};
}

void checkGrid(){
    int x=0, o=0;
    char enter;
    bool possible=true;

    for(auto i:grid){
        for(auto j:i){
            if(j=='X'){
                x++;    
            }
            else if(j=='O'){
                o++;
            }
        }
    }

    if(x<0) possible=false;
    else{
        if(x!=o && x!=o+1) possible=false;
    }
    
    if(!possible){
        cout<<"no\n";
        return;
    }

    auto [xwin, owin]=checkVictory();

    if(xwin>0 && owin>0){
        possible=false;
    }
    if(xwin>0 && x!=o+1){
        possible=false;
    }
    if(owin>0 && x!=o){
        possible=false;
    }

    if(possible) cout<<"yes\n";
    else cout<<"no\n";
    
}

int main() {
    int n;

    cin>>n;
    grid.resize(3, vector<char>(3));

    for(int i=0;i<n;i++){
        for(auto &i:grid){
            for(auto &j:i) cin>>j;
        }
        // printGrid();
        checkGrid();
        // cin>>enter;
    }
    
    return 0;
}