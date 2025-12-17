/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int>>table;
vector<vector<int>> dp;

int GetMaxScore(){
    //도시 1개 == 자기자신(시작점, 아직 출발 X, 기내식 안먹음) -> 0점
    dp[1][1]=0;
    
    for(int cnt=1;cnt<m;cnt++){
        for(int cur=1;cur<=n;cur++){
            if(dp[cur][cnt]==-1)continue;//현재까지 도달할 길이 없음
            
            for(int nxt=cur+1;nxt<=n;nxt++){
                if(table[cur][nxt]==0) continue;//가는 비행기가 없음음
                dp[nxt][cnt+1]=max(dp[nxt][cnt+1], dp[cur][cnt]+table[cur][nxt]);
            }
        }
    }
    
    
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    return *max_element(dp[n].begin(), dp[n].end());
}

int main()
{
    cin>>n>>m>>k;
    
    table.assign(n+1, vector<int>(n+1, 0));
    dp.assign(n+1, vector<int>(m+1, -1));
    
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        table[a][b]=max(table[a][b], c);//같은 경로일 경우 높은 점수만 반영
    }
    
    cout<<GetMaxScore()<<"\n";
    

    return 0;
}