#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef tuple<int, int, int> TIII;
/*
    풀이과정: 다익스트라
    동전의 크기가 최소인 곳으로 고고링
    우선순위 큐를 사용한다
*/


int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int dijkstra(vector<vector<int>>& cave, int n, int r, int c){
    vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
    visited[r][c]=cave[r][c];
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
    pq.push({cave[r][c],r,c});

    
    while(!pq.empty()){
        auto[curWeight, curR, curC]=pq.top();
        pq.pop();

        //if(cave[curR][])

        for(int i=0;i<4;i++){
            int nextR=curR+dr[i];
            int nextC=curC+dc[i];
            

            if(nextR<0||nextR>=n||nextC<0||nextC>=n) continue;
            
            int nextWeight=cave[nextR][nextC];
            if(visited[nextR][nextC]>visited[curR][curC]+nextWeight){
                visited[nextR][nextC]=min(visited[nextR][nextC], visited[curR][curC]+nextWeight);
                pq.push({visited[curR][curC]+nextWeight, nextR, nextC});
            }
        }
    }
    
    /*
    for(auto i:visited){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------------\n";*/

    return visited[n-1][n-1];
}

int main() {
    int n;
    int i=1;
    while(1){
        cin>>n;
        if(n==0) break;

        vector<vector<int>> cave(n, vector<int>(n));

        for(auto &i:cave){
            for(auto &j :i){
                cin>>j;
            }
        }

        /*
        for(auto i:cave){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";*/

        cout<<"Problem "<<i<<": "<<dijkstra(cave, n, 0, 0)<<"\n";
        i++;
        
    }
    return 0;
}