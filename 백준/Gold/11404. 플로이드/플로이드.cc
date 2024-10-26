#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<vector<int>>adjList;

void floyd(){
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                adjList[a][b]=min(adjList[a][b], adjList[a][k]+adjList[k][b]);
            }
        }
    }
}


int main() {
    cin>>n>>m;

    adjList.assign(n+1, vector<int>(n+1, 1e9));

    for(int i=1;i<=n;i++){
        adjList[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from][to]=min(adjList[from][to], weight);
    }

    floyd();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adjList[i][j]==1e9){
                cout<<0<<" ";
            }
            else
                cout<<adjList[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}