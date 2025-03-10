#include <bits/stdc++.h>
using namespace std;

/*
    풀이과정: 
    1~3으로 길이 m(최대 10)의 수열을 만드는 경우의 수
    ex) 길이가 3이라면,
    1 1 1, 1 1 2, 1 1 3, 1 2 1,...
    이때, 길이가 m까지이므로 n중 반복문으로 풀이 불가 -> 재귀 사용

    특정 조합을 만들었을 때, 해당 조합으로 인해 터지는 칸 수 계산 필요

    탈출 조건
    터트린 폭탄 개수가 m개라면 탈출
    이때, 폭탄으로 인해 터진 구역 체크하고 리턴해야 함

    데이터 원복
    isExploded 벡터 초기화
    visited 초기화

    1: 맵 순회-방문하지 않은 폭탄 있는 위치(1)만 확인
    2: 3개 유형 폭탄 순회
        여기서 backtracking 재귀 호출

    시간복잡도:
    중복 허용 - 2 1 1, 1 2 1, 1 1 2처럼 위치별로 터지는 칸 수 다 다름
    O(n^n), n max=10 이므로 10^10=10억 정도..?

    자료구조:
    isExploded: 폭탄으로 인해 터진 칸 확인
    visited: 폭탄 방문했는지 확인용
*/

int n;
int bombCnt;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> isExploded;
vector<pair<int, int>> bombloc;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int diagr[4]={-1,-1,1,1};
int diagc[4]={-1,1,-1,1};
int ans=0;

void explode1(int r, int c){
    for(int j=r-2;j<=r+2;j++){
        if(j<0||j>=n) continue;

        isExploded[j][c]++;
    }
}

void recoverExplode1(int r, int c){
    for(int j=r-2;j<=r+2;j++){
        if(j<0||j>=n) continue;

        isExploded[j][c]--;
    }
}

void explode2(int r, int c){
    isExploded[r][c]++;
    for(int j=0;j<4;j++){
        int exR=r+dr[j];
        int exC=c+dc[j];

        if(exR<0||exR>=n||exC<0||exC>=n) continue;
        isExploded[exR][exC]++;
    }
}

void recoverExplode2(int r, int c){
    isExploded[r][c]--;
    for(int j=0;j<4;j++){
        int exR=r+dr[j];
        int exC=c+dc[j];

        if(exR<0||exR>=n||exC<0||exC>=n) continue;
        isExploded[exR][exC]--;
    }
}

void explode3(int r, int c){
    isExploded[r][c]++;
    for(int j=0;j<4;j++){
        int exR=r+diagr[j];
        int exC=c+diagc[j];

        if(exR<0||exR>=n||exC<0||exC>=n) continue;
        isExploded[exR][exC]++;
    }
}

void recoverExplode3(int r, int c){
    isExploded[r][c]--;
    for(int j=0;j<4;j++){
        int exR=r+diagr[j];
        int exC=c+diagc[j];

        if(exR<0||exR>=n||exC<0||exC>=n) continue;
        isExploded[exR][exC]--;
    }
}


void backtracking(int depth){
    if(depth==0){                
        //터진 칸 수 최댓값 업데이트
        int tmp=0;

        for(auto i:isExploded){
            for(auto j:i){
                if(j!=0) tmp++;
            }
        }

        ans=max(ans, tmp);

        return;
    }

    auto [nextR, nextC]=bombloc[depth-1];

    explode1(nextR, nextC);
    backtracking(depth-1);
    recoverExplode1(nextR, nextC);
    

    explode2(nextR, nextC);
    backtracking(depth-1);
    recoverExplode2(nextR, nextC);
    

    explode3(nextR, nextC);
    backtracking(depth-1);
    recoverExplode3(nextR, nextC);

    return;
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    isExploded.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j]==1) bombloc.push_back({i, j});
        }
    }

    bombCnt=bombloc.size();
    backtracking(bombCnt);

    cout<<ans<<"\n";

    return 0;
}
