#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={
{1,0,0,0,0,0,0,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0},
{0,-1,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0},
{0,0,-1,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,-1,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,-1,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,-1,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,-1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,-1,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,-1,0,0},
{0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,-1,0},
{0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,-1}
};

struct Pos{
    int m,n,o,p,q,r,s,t,u,v,w;
};

//넘나 괴로운 문제

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int m,n,o,p,q,r,s,t,u,v,w;
    cin>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w;

    /*
        C++에서 다차원 배열은 오른쪽 인덱스가 가장 빠르게 변하며 
        메모리에 연속 저장되기 때문에, 
        연산 성능을 높이려면 가장 자주 순회하는 축을
        배열의 마지막 인덱스로 두는 것이 좋다.
    */
    int tomato[w][v][u][t][s][r][q][p][o][n][m];
    int vdays[w][v][u][t][s][r][q][p][o][n][m];

    memset(vdays, -1, sizeof(vdays));//미방문==-1로

    int ans=0;
    int ripe=0;

    int totalTomato=m*n*o*p*q*r*s*t*u*v*w;

    queue<pair<Pos, int>> que;

    for(int a=0;a<w;a++)for(int b=0;b<v;b++)for(int c=0;c<u;c++)
    for(int d=0;d<t;d++)for(int e=0;e<s;e++)for(int f=0;f<r;f++)
    for(int g=0;g<q;g++)for(int h=0;h<p;h++)for(int i=0;i<o;i++)
    for(int j=0;j<n;j++)for(int k=0;k<m;k++){
        cin>>tomato[a][b][c][d][e][f][g][h][i][j][k];

        //그때그때 익은토마토면 0일로 방문처리하고 큐에 넣기
         if(tomato[a][b][c][d][e][f][g][h][i][j][k]==1){
             ripe++;
             vdays[a][b][c][d][e][f][g][h][i][j][k]=0;
             que.push({{k,j,i,h,g,f,e,d,c,b,a},0});//큐에 넣을 때 순서 지키기
        }
             //빈 공간이므로 총 토마토 개수에서 제외
        else if(tomato[a][b][c][d][e][f][g][h][i][j][k]==-1) totalTomato--;
    }

    // cout<<que.size()<<"\n";

    while(!que.empty()){
        auto [curPos, day]=que.front();
        que.pop();
        ans=day;

        for(auto d:dir){
            int nxtM=curPos.m+d[0];
            int nxtN=curPos.n+d[1];
            int nxtO=curPos.o+d[2];
            int nxtP=curPos.p+d[3];
            int nxtQ=curPos.q+d[4];
            int nxtR=curPos.r+d[5];
            int nxtS=curPos.s+d[6];
            int nxtT=curPos.t+d[7];
            int nxtU=curPos.u+d[8];
            int nxtV=curPos.v+d[9];
            int nxtW=curPos.w+d[10];

            //범위체크
            if(nxtM<0||nxtM>=m||
                nxtN<0||nxtN>=n||
                nxtO<0||nxtO>=o||
                nxtP<0||nxtP>=p||
                nxtQ<0||nxtQ>=q||
                nxtR<0||nxtR>=r||
                nxtS<0||nxtS>=s||
                nxtT<0||nxtT>=t||
                nxtU<0||nxtU>=u||
                nxtV<0||nxtV>=v||
                nxtW<0||nxtW>=w) continue;

                //안익은 토마토인데 미방문 상태라면(-1일) 
            if(tomato[nxtW][nxtV][nxtU][nxtT][nxtS][nxtR][nxtQ][nxtP][nxtO][nxtN][nxtM]==0
               && vdays[nxtW][nxtV][nxtU][nxtT][nxtS][nxtR][nxtQ][nxtP][nxtO][nxtN][nxtM]==-1){
                vdays[nxtW][nxtV][nxtU][nxtT][nxtS][nxtR][nxtQ][nxtP][nxtO][nxtN][nxtM]=day+1;
                ripe++;
                que.push({{nxtM,nxtN,nxtO,nxtP,nxtQ,nxtR,nxtS,nxtT,nxtU,nxtV,nxtW}, day+1});
                
            }
        }
    }

    // cout<<ripe<<" "<<totalTomato<<"\n";
    if(ripe==totalTomato) cout<<ans<<"\n";
    else cout<<-1<<"\n";
    
    
    
    return 0;
}