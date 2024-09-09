#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> PII;

int n, e;
vector<vector<PII>> adjList;
vector<int> shortestPath;
int src, dest;

void djikstra(int start){
    shortestPath[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(shortestPath[curNode]<curWeight){
            continue;
        }

        for(int i=0;i<adjList[curNode].size();i++){
            int nextNode = adjList[curNode][i].second;
            int nextWeight = adjList[curNode][i].first;

            if(shortestPath[nextNode]>shortestPath[curNode]+nextWeight){
                shortestPath[nextNode]=shortestPath[curNode]+nextWeight;
                pq.push({shortestPath[nextNode], nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>e;

    adjList.resize(n+1);
    shortestPath.assign(n+1, INT_MAX);

    for(int i=0;i<e;i++){
        int from, to, weight;

        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
    }

    cin>>src>>dest;

    djikstra(src);

    cout<<shortestPath[dest]<<"\n";
    
    return 0;
}