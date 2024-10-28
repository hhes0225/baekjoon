#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

//n: 지역 개수(node)
//m: 수색 범위
//r: 길 개수(edge)
int n, m, r;
vector<vector<PII>> adjList;
vector<int> visitedVal;//가치 저장
vector<int> visitedDist;//거리 저장
vector<int> values;
vector<int> maxItems;

void dijkstra(int start){
    //fill(visitedVal.begin(), visitedVal.end(), 0);
    fill(visitedDist.begin(), visitedDist.end(), 1e9);
    //visitedVal[start]=values[start];
    visitedDist[start]=0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        //여기까지 가는 데 필요한 거리

        pq.pop();

        if(curWeight>visitedDist[curNode]){
            continue;
        }



        for(auto it:adjList[curNode]){
            int nextNode = it.second;
            int nextWeight=it.first;

            if(visitedDist[nextNode]>visitedDist[curNode]+nextWeight){
                //visitedVal[nextNode]=max(visitedVal[nextNode], visitedVal[curNode]+values[nextNode]);
                visitedDist[nextNode]=visitedDist[curNode]+nextWeight;
                //nextNode까지 가는 데 필요한 거리 저장
    
                pq.push({visitedDist[nextNode], nextNode});
            }

            
        }
    }

    int totalval=0;

    //visitedDist가 start 노드에서 나머지 노드까지 가는 길 저장하고 있으므로
    //탐색범위보다 길이 길면 패스, 길이 짧을때만 value를 더한다
    for(int i=1;i<=n;i++){
        if(visitedDist[i]<=m){
            totalval+=values[i];
        }
    }
    maxItems.push_back(totalval);
}

int main() {
    cin>>n>>m>>r;

    adjList.resize(n+1);
    
    //visitedVal.assign(n+1, 0);
    visitedDist.assign(n+1, 1e9);
    values.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>values[i];
    }

    for(int i=0;i<r;i++){
        int from, to, weight;
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    for(int i=1;i<=n;i++){
        dijkstra(i);

        /*
        for(auto it:visitedVal){
            cout<<it<<" ";
        }
        cout<<"\n";

        for(auto it:visitedDist){
            cout<<it<<" ";
        }
        cout<<"\n";
        */
    }

    cout<<*max_element(maxItems.begin(), maxItems.end());
    
    return 0;
}