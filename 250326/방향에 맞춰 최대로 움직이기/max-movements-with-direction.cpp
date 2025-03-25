#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> num;
vector<vector<int>> move_dir;
int inR, inC;

int maxMove=0;

int dr[9]={0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9]={0, 0, 1, 1, 1, 0, -1, -1, -1};

void backtracking(int r, int c, int moves){
    int curDir=move_dir[r][c];//방향, dr, dc 인덱스로 사용 예정
    int curVal=num[r][c];//현재 값
    bool canMove=false;

    //cout<<curDir<<" "<<curVal<<"\n";


    //만약 더 이상 움직일 곳이 없다면
    //이동할 수 있는 구역 하나씩 탐색하며 자기보다 더 큰 수가 없다면
    //재귀 탈출
    // 해당 칸의 방향대로 쭉 직선 탐색해나가면서
    //탐색한 칸이 현재 칸보다 값 크면 해당 칸으로 재귀 돌리기
    int nextR=r+dr[curDir], nextC=c+dc[curDir];
    while(nextR>=0&&nextR<n&&nextC>=0&&nextC<n){
        if(num[nextR][nextC]>curVal){
            //cout<<r<<", "<<c<<"에서 "<<nextR<<", "<<nextC<<"로 이동 가능\n";
            canMove=true;
            backtracking(nextR, nextC, moves+1);
            
        }
        nextR+=dr[curDir];
        nextC+=dc[curDir];
    }

    if(!canMove){
        //cout<<"이동 불가\n";
        maxMove=max(maxMove, moves);
        return;
    }
    
}


int main() {
    cin >> n;

    num.resize(n, vector<int>(n));
    move_dir.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> inR >> inC;

    // Please write your code here.
    backtracking(inR-1, inC-1, 0);

    cout<<maxMove<<"\n";

    return 0;
}
