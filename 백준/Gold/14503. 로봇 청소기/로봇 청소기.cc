#include <bits/stdc++.h>
using namespace std;

/*
    아이디어:
    - while문으로 특정 조건 종료될 때까지 반복
    - 4방향을 for로 탐색
    - 더 이상 탐색 불가능할 경우, 뒤로 한 칸 후진
    - 후진이 불가능하면 종료

    시간복잡도
    O(NM): 50^2=2500<2억

    자료구조
    - grid: 2차원 배열
    - 로봇청소기 위치, 방향, 전체 청소한 곳 수
*/
int n, m;
vector<vector<int>> room;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int cleanCnt=0;

void simulation(int r, int c, int d){
    while(1){
        room[r][c]=2;//청소된 상태==2
        bool sw=false;
        
        for(int i=0;i<4;i++){
            int dir=(3+d-i);
            int nr=r+dr[dir%4];
            int nc=c+dc[dir%4];

            if(nr<0||nr>=n||nc<0||nc>=m) continue;
            if(room[nr][nc]==0){
                d=dir%4;//방향 반시계 90 전환
                r=nr; c=nc;//한 칸 전진
                sw=true;
                break;
            }
        }

        if(sw==false){
            //안 청소된 빈 칸 없는 경우.
            int nr=r+dr[(d+2)%4];
            int nc=c+dc[(d+2)%4];//후진

            if(nr<0||nr>=n||nc<0||nc>=m) break;
            //후진 가능한가?
            if(room[nr][nc]==1){
                break;//작동 멈춤
            }
            else{
                r=nr;c=nc;
            }
        }
        
    }
}

int main() {
    cin>>n>>m;

    int r, c, d;
    cin>>r>>c>>d;

    room.resize(n, vector<int> (m));

    for(auto &i:room){
        for(auto &j:i){
            cin>>j;
        }
    }
    
    simulation(r, c, d);

    
    for(auto i:room){
        for(auto j:i){
            if(j==2) cleanCnt++;
            //cout<<j<<" ";
        }
        //cout<<"\n";
    }
    //cout<<"\n";

    cout<<cleanCnt<<"\n";
    
    return 0;
}