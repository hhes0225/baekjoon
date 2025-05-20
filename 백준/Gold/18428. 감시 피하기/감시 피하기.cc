 #include <bits/stdc++.h>
using namespace std;

//https://transferhwang.tistory.com/565
//dfs version

int n;
vector<vector<char>> grid;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool flag;
vector<pair<int, int>> teacher, blank;//선생님 좌표, 빈칸 좌표

bool canWatch(int nx, int ny, int dir){
    //한방향으로만 쭈우우욱
    while(1){
        nx+=dx[dir];
        ny+=dy[dir];

        if(nx<0||nx>=n||ny<0||ny>=n||grid[nx][ny]=='O') break;
        //장애물 만나거나 범위 벗어나면 종료
        //grid[nx][ny] 순서 맨 마지막으로 가야 함!!! 안그럼 outofbounds
        if(grid[nx][ny]=='S') return true;//학생 만나면 감시 성공
    }

    return false;//감시 실패
}

bool isPossible(){
    for(int i=0;i<teacher.size();i++){
        auto [x,y]=teacher[i];

        for(int j=0;j<4;j++){
            if(canWatch(x,y,j)) return false;//감시 성공->감시피하기 실패
        }
    }

    return true;//감시 전부 피했으므로 성공
}

void dfs(int cnt){//cnt==장애물 설치 위치
    if(cnt==3){
        if(isPossible()) flag=true;
        return;
    }

    for(int i=0;i<blank.size();i++){
        auto [x,y]=blank[i];

        if(grid[x][y]=='X'){
            grid[x][y]='O';
            dfs(cnt+1);
            grid[x][y]='X';
        }
    }
}

int main(void){
    cin>>n;

    grid.resize(n, vector<char>(n));

    for(auto &i:grid){
        for(auto&j:i){
            cin>>j;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='T') teacher.push_back({i, j});
            else if(grid[i][j]=='X') blank.push_back({i, j});
        }
    }

    dfs(0);

    if(flag) cout<<"YES";
    else cout<<"NO";


    return 0;
}