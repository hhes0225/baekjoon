#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define LIMIT 100001
using namespace std;
typedef pair<int, int> PII;

vector<vector<PII>> adjList;
vector<int> visited;
int src, dst;

void dijkstra(int start){
    visited[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight=pq.top().first;
        int x=curNode;

        pq.pop();
        
        if(visited[curNode]<curWeight){
            continue;
        }
        //cout<<curNode<<"\n";

        //0초 후 x*2
        if(visited[x*2]>visited[x] && (x*2>=0&&x*2<LIMIT)){
            visited[x*2]=visited[x];
            pq.push({visited[x*2], x*2});
        }

        //1초 후 x-1
        if(visited[x-1]>visited[x]+1 && (x-1>=0&&x-1<LIMIT)){
            visited[x-1]=visited[x]+1;
            pq.push({visited[x-1], x-1});
        }

        //1초 후 x+1
        if(visited[x+1]>visited[x]+1 && (x+1>=0&&x+1<LIMIT)){
            visited[x+1]=visited[x]+1;
            pq.push({visited[x+1], x+1});
        }

        
    }
}

int main() {
    cin>>src>>dst;

    adjList.resize(LIMIT);
    visited.assign(LIMIT, INT_MAX);

    dijkstra(src);
    cout<<visited[dst]<<"\n";
    
    return 0;
}