#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    그냥 dfs만 사용해서는 시간초과 발생.

    memoization을 이용해야 시간초과 발생하지 않음
*/

vector<vector<int>> heightMap;
vector<vector<int>> downhillRouteCase;//
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int m, n;

void printMap(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<downhillRouteCase[i][j]<<" ";
        }
        cout<<endl;
    }
}

int dfs(int dm, int dn){
    //목표 지점에 도달한 경우
    if(dm==m-1&&dn==n-1){
        return 1;
    }

    //이미 계산된 경우
    if(downhillRouteCase[dm][dn]!=-1){
        return downhillRouteCase[dm][dn];
    }

    downhillRouteCase[dm][dn]=0;
    

    for(int i=0;i<4;i++){
        int new_m=dm+dx[i];
        int new_n=dn+dy[i];
        
        //행 범위 벗어나는 경우
        if(new_m<0 || new_m>=m){
            continue;
        }
        //열 범위 벗어나는 경우
        if(new_n<0 || new_n>=n){
            continue;
        }
        //이동할 경로가 내리막이 아닌 경우
        if(heightMap[dm][dn]<=heightMap[new_m][new_n]){
            continue;
        }
        
        //unvisited한 칸 체크할 필요 없음(해당 칸까지 가는 경우의 수를 찾아야 하기 때문-재방문될 수 있음)
        downhillRouteCase[dm][dn]+=dfs(new_m, new_n);        
    }

    return downhillRouteCase[dm][dn];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;

    heightMap.assign(m, vector<int>(n, 0));
    downhillRouteCase.assign(m, vector<int>(n, -1));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>heightMap[i][j];
        }
    }

    int result = dfs(0, 0);

    cout<<result<<"\n";

    //printMap();
    //cout<<downhillRouteCase[m-1][n-1]<<"\n";
    
    return 0;
}