#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> PII;

int v, e;
int srcNode;
int from, to, weight;

vector<vector<PII>> adjList;
vector<int> shortestPath;

void djikstra(int start){
    shortestPath[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(curWeight>shortestPath[curNode])continue;

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

    cin>>v>>e>>srcNode;

    adjList.resize(v+1);
    shortestPath.assign(v+1, INT_MAX);
    
    for(int i=0;i<e;i++){
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
    }

    djikstra(srcNode);

    for(int i=1;i<shortestPath.size();i++){
        if(shortestPath[i]!=INT_MAX){
            cout<<shortestPath[i]<<"\n";
        }
        else{
            cout<<"INF\n";
        }
    }
    return 0;
}