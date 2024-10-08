#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int party, client;
vector<vector<int>> shortestPath;
int from, to, timeLimit;

//플로이드-워셜 알고리즘의 점화식
//D_ab=min(D_ab, D_ak+D+kb)

//모든 노드에서 모든 노드까지의 최소경로이므로 
//굳이 시작 노드 지정할 필요 없음
void FloydWarshall(){
    for(int k=1;k<party+1;k++){
        for(int a=1;a<party+1;a++){
            for(int b=1;b<party+1;b++){
                shortestPath[a][b]=min(shortestPath[a][b], shortestPath[a][k]+shortestPath[k][b]);
            }
        }
    }
}

void PrintGraph(){
    for(int i=1;i<party+1;i++){
        for(int j=1;j<party+1;j++){
            cout<<shortestPath[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    cin>>party>>client;

    shortestPath.assign(party+1, vector<int>(party+1, INT_MAX));

    for(int i=1;i<party+1;i++){
        for(int j=1;j<party+1;j++){
            cin>>shortestPath[i][j];
        }
    }

    //PrintGraph();

    FloydWarshall();

    //PrintGraph();

    for(int i=0;i<client;i++){
        cin>>from>>to>>timeLimit;

        if(shortestPath[from][to]>timeLimit){
            cout<<"Stay here\n";
        }
        else{
            cout<<"Enjoy other party\n";
        }
    }
    
    return 0;
}