#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> PII;

int node, edge;
int src, dest;
vector<vector<PII>> adjList;
vector<int> shortestPath;
vector<int> route;

void dijkstra(int start){
    shortestPath[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode=pq.top().second;
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

                route[nextNode]=curNode;
                pq.push({shortestPath[nextNode], nextNode});
            }
        }
    }
}

vector<int> getPath(int dest){
    vector<int> path;

    for(int at = dest; at != -1; at=route[at]){
        path.push_back(at);
    }

    reverse(path.begin(), path.end());
    return path;
}

void printVector(vector<int>& vec){
    for(auto it:vec){
        cout<<it<<" ";
    }
    cout<<"\n";
}


int main() {
    cin>>node>>edge;

    adjList.resize(node+1);
    shortestPath.assign(node+1, INT_MAX);
    route.assign(node+1, -1);

    for(int i=0;i<edge;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
    }

    cin>>src>>dest;

    dijkstra(src);

    //printVector(shortestPath);

    cout<<shortestPath[dest]<<"\n";
    
    vector<int> path = getPath(dest);
    cout<<path.size()<<"\n";
    printVector(path);
    
    return 0;
}