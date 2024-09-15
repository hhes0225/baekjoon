#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

int node, edge, dest;
vector<vector<PII>> adjList;
vector<int> shortestPath;
vector<int> totalPath;

void dijkstra(int start){
    shortestPath[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if(shortestPath[curNode]<curDist){
            continue;
        }

        for(int i=0;i<adjList[curNode].size();i++){
            int nextNode=adjList[curNode][i].second;
            int nextDist=adjList[curNode][i].first;

            if(shortestPath[nextNode]>shortestPath[curNode]+nextDist){
                shortestPath[nextNode]=shortestPath[curNode]+nextDist;
                pq.push({shortestPath[nextNode], nextNode});
            }
        }
    }
}

void printShortestPath(){
    for(int j=1;j<shortestPath.size();j++){
        cout<<shortestPath[j]<<" ";
    }
    cout<<"\n";
}

void printTotalPath(){
    for(int j=1;j<totalPath.size();j++){
        cout<<totalPath[j]<<" ";
    }
    cout<<"\n";
}

int main() {
    cin>>node>>edge>>dest;

    adjList.resize(node+1);
    totalPath.assign(node+1, 0);

    for(int i=0;i<edge;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
    }

    for(int i=1;i<totalPath.size();i++){
        shortestPath.assign(node+1, INT_MAX);
        dijkstra(i);
        if(shortestPath[dest]!=INT_MAX)
            totalPath[i]+=shortestPath[dest];


        shortestPath.assign(node+1, INT_MAX);
        dijkstra(dest);
        if(shortestPath[i]!=INT_MAX)
            totalPath[i]+=shortestPath[i];

    }

    
    cout<<*max_element(totalPath.begin(), totalPath.end())<<"\n";
    
    
    return 0;
}