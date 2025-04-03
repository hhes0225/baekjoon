#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

int rowMaxLen(int n){
    int maxLen=1;
    //가로
    for(int i=0;i<n;i++){
        int tmpLen=1;
        for(int j=1;j<n;j++){
            if(grid[i][j]==grid[i][j-1]){
                tmpLen++;
            }
            else {
                maxLen=max(maxLen, tmpLen);
                tmpLen=1;
            }
        }
        maxLen=max(maxLen, tmpLen);
    }

    return maxLen;
}

int colMaxLen(int n){
    int maxLen=1;
    //세로
    for(int i=0;i<n;i++){
        int tmpLen=1;
        for(int j=1;j<n;j++){
            if(grid[j][i]==grid[j-1][i]){
                tmpLen++;
            }
            else {
                maxLen=max(maxLen, tmpLen);
                tmpLen=1;
            }
        }
        maxLen=max(maxLen, tmpLen);
    }

    return maxLen;
}

//각 칸마다 우측 칸과 변경, 아래측 칸과 변경하면 아마 다 커버될듯?
void changeRow(int r, int c, int n){
    if(c<n-1){//마지막 열은 우측이 없음
        int tmp=grid[r][c];
        grid[r][c]=grid[r][c+1];
        grid[r][c+1]=tmp;
    }
}

void changeCol(int r, int c, int n){
    if(r<n-1){//마지막 행은 아래측이 없음
        int tmp=grid[r][c];
        grid[r][c]=grid[r+1][c];
        grid[r+1][c]=tmp;
    }
}

int main() {
    int n;
    cin>>n;

    grid.resize(n, vector<char>(n));

    for(auto&i:grid){
        for(auto&j:i) cin>>j;
    }

    // for(auto i:grid){
    //     for(auto j:i) cout<<j<<" ";
    //     cout<<"\n";
    // }

    int maxLen=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //우측 칸과 변경하는 경우
            changeRow(i,j,n);
            maxLen=max({maxLen, rowMaxLen(n), colMaxLen(n)});
            changeRow(i, j, n);//원복

            //아래측 칸과 변경하는 경우
            changeCol(i,j,n);
            maxLen=max({maxLen, rowMaxLen(n), colMaxLen(n)});
            changeCol(i,j,n);//원복

        }
    }

    cout<<maxLen<<"\n";
    
    return 0;
}