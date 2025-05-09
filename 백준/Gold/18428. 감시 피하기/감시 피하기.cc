#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int n;

void printGrid(){
    for(auto i:grid){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

bool meetStudent(int r, int c){
    int m=0;
    //선생님과 같은 row인가?
    for(int i=r;i<n;i++){
        if(grid[i][c]=='O') break;
        if(grid[i][c]=='S') m++;
    }

    for(int i=r;i>=0;i--){
        if(grid[i][c]=='O') break;
        if(grid[i][c]=='S') m++;
    }

    //선생님과 같은 col인가?
    for(int i=c;i<n;i++){
        if(grid[r][i]=='O') break;
        if(grid[r][i]=='S') m++;
    }

    for(int i=c;i>=0;i--){
        if(grid[r][i]=='O') break;
        if(grid[r][i]=='S') m++;
    }

    if(m==0) return true;
    else return false;
}

bool canAvoidAll(){
    bool notMeet=true;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='T'){
                notMeet=(notMeet&&meetStudent(i, j));
            }
        }
    }
    // if(notMeet) cout<<"yes\n";
    // else cout<<"no\n";
    
    return notMeet;
}


int caset=0;
bool avoidAllTeacher=false;

void backtracking(int r, int c, int obLimit){
    if(obLimit==0){
        caset++;
        avoidAllTeacher=(avoidAllTeacher||canAvoidAll());

        // if(canAvoidAll()){
        //     printGrid();
        // }
        return;
    }

    if(avoidAllTeacher) return;

    //row(서로 다른 row에 있어야 함)
    for(int i=r+1;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X'){
                grid[i][j]='O';
                backtracking(i,j,obLimit-1);
                grid[i][j]='X';
            }
        }
    }

    //col(서로 다른 col에 있어야 함)
    for(int i=0;i<n;i++){
        for(int j=c+1;j<n;j++){
            if(grid[i][j]=='X'){
                grid[i][j]='O';
                backtracking(i,j,obLimit-1);
                grid[i][j]='X';
            }
        }
    }
}

int main() {
    cin>>n;

    grid.resize(n, vector<char>(n));

    for(auto &i:grid){
        for(auto &j:i) cin>>j;
    }

    
    backtracking(-1,-1,3);

    if(avoidAllTeacher){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    
    return 0;
}